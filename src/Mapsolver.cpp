#include "Mapsolver.hpp"
#include "Case.hpp"

Mapsolver::Mapsolver(map* target_map) : m_map(target_map) {
    
}

void Mapsolver::solve_tremaux() {
    int largeur = m_map->get_largeur();
    int hauteur = m_map->get_hauteur();
    int taille_grille = largeur * hauteur;

    // init traces_craie_tremaux
    traces_craie_tremaux.resize(taille_grille, 0); // 0,1,2 passages par case

    int index_courant = m_map->get_index_start();


}

void Mapsolver::solve_dijkstra() {

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
