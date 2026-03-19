#include "Mapsolver.hpp"
#include "Case.hpp"
#include <queue>
#include <algorithm> //std::reverse
#include <chrono>

Mapsolver::Mapsolver(map* target_map) : m_map(target_map) {
    
}


void Mapsolver::solve_BFS() {

    //initialisation
    auto start_time = std::chrono::high_resolution_clock::now();
    current_algo = AlgoType::BFS;
    chemin_final_bfs.clear();

    int depart = m_map->get_index_start();
    int fin = m_map->get_index_end();
    int nb_cases = m_map->get_largeur() * m_map->get_hauteur();

    std::queue<int> file;
    std::vector<int> parent(nb_cases, -1);
    std::vector<bool> visite(nb_cases, false);

    file.push(depart);
    visite[depart] = true;

    bool trouve = false;
    while(!file.empty()) {
        int actuel = file.front();
        file.pop();

        if(actuel == fin) {
            trouve = true;
            auto end_time = std::chrono::high_resolution_clock::now();
            bfs_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            printf("BFS trouve en %.2f ms\n", bfs_time);
            break;

        }

        for(const auto& v : get_voisins(actuel)) {
            if(v.type != casetype::Plein && !visite[v.index]) {
                visite[v.index] = true;
                parent[v.index] = actuel;
                file.push(v.index);
            }
        }
    }

    //REMONTER ET STOCKER LE CHEMIN
        if(trouve) {
            int etape = fin;

            while(etape != -1) {
                chemin_final_bfs.push_back(etape);
                etape = parent[etape];
            }

            std::reverse(chemin_final_bfs.begin(), chemin_final_bfs.end());

            printf("Chemin trouve ! Longueur : %zu\n", chemin_final_bfs.size());
        }
        else {
             printf("Aucun chemin trouve\n");
        }

        // DEBUG
        for (int i = 0; i < chemin_final_bfs.size(); i++) {
            printf("%d ", chemin_final_bfs[i]);
        }
        printf("\n");
}

void Mapsolver::solve_DFS() {

    auto start_time = std::chrono::high_resolution_clock::now();

    current_algo = AlgoType::DFS;
    int n = m_map->get_largeur() * m_map->get_hauteur();

    std::vector<bool> visited(n, false);
    std::vector<int> path;

    int start = m_map->get_index_start();
    int end = m_map->get_index_end();

    path.push_back(start);
    visited[start] = true;

    while (!path.empty()) {

        int current = path.back();

        if (current == end) {
            chemin_final_dfs = path;
            printf("Chemin trouve ! Taille : %zu\n", path.size());
            auto end_time = std::chrono::high_resolution_clock::now();
            dfs_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
            printf("DFS trouve en %.2f ms\n", dfs_time);
            return;
        }

        auto voisins = get_voisins(current);

        bool avance = false;

        //obligation de refaire une boucle car position end supposée inconnue
        for (const auto& v : voisins) {
            if(v.type == casetype::End){
                visited[v.index] = true;
                path.push_back(v.index);
                chemin_final_dfs = path;
                printf("Chemin trouve ! Taille : %zu\n", path.size());
                auto end_time = std::chrono::high_resolution_clock::now();
                dfs_time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
                printf("DFS trouve en %.2f ms\n", dfs_time);
                return;
            }
        }
        for (const auto& v : voisins) {

            if (v.type != casetype::Plein && !visited[v.index]) {
                visited[v.index] = true;
                path.push_back(v.index);
                avance = true;
                break;
            }
        }

        //BACKTRACK (ultra important)
        if (!avance) {
            path.pop_back();
        }
    }

    printf("Pas de chemin\n");
}



std::vector<voisin> Mapsolver::get_voisins(int index) const {
    std::vector<voisin> liste_voisins;
    
    //position de la case actuelle
    ivec2 position = m_map->getgrille()[index].getcoord();
    int x = position.x;
    int y = position.y;

    // Droite
    if(x + 1 < m_map->get_largeur()) {
        int id = m_map->get_id({x + 1, y});
        liste_voisins.push_back({id, m_map->getgrille()[id].getcasetype()});
    }
    // Bas
    if(y + 1 < m_map->get_hauteur()) {
        int id = m_map->get_id({x, y + 1});
        liste_voisins.push_back({id, m_map->getgrille()[id].getcasetype()});
    }
    // Gauche
    if(x - 1 >= 0) {
        int id = m_map->get_id({x - 1, y});
        liste_voisins.push_back({id, m_map->getgrille()[id].getcasetype()});
    }
    // Haut
    if(y - 1 >= 0) {
        int id = m_map->get_id({x, y - 1});
        liste_voisins.push_back({id, m_map->getgrille()[id].getcasetype()});
    }

    return liste_voisins;
}

const std::vector<int>& Mapsolver::get_chemin() const {
    if (current_algo == AlgoType::BFS) {
        return chemin_final_bfs;
    } else if (current_algo == AlgoType::DFS) {
        return chemin_final_dfs;
    } else {
        static std::vector<int> empty_chemin;
        return empty_chemin; 
    }
}

AlgoType Mapsolver::get_current_algo() const {
    return current_algo;
}

void Mapsolver::reset() {
    chemin_final_bfs.clear();
    chemin_final_dfs.clear();
    bfs_time = 0.0;
    dfs_time = 0.0;
    // clear toute case non vide
    for (Case &c : m_map->getgrille()) {
        if (c.getcasetype() != casetype::Vide) {
            c.setcasetype_reset(casetype::Vide);
        }
    }
    current_algo = AlgoType::NONE;
}