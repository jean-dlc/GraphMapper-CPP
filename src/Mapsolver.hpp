// ============================================================
// Mapsolver — Moteur de résolution du labyrinthe
// Implémente BFS (chemin optimal) et DFS (backtracking).
// Mesure le temps d'exécution via std::chrono.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

#ifndef MAPSOLVER_HPP
#define MAPSOLVER_HPP

#include "map.hpp"
#include <vector>

enum class AlgoType {
    NONE,
    BFS,
    DFS
};




class Mapsolver {
public:
    //pointer vers map
    Mapsolver(map* target_map);

    void solve_BFS();
    void solve_DFS();
    void reset(); 
    double get_last_time() const;
    const std::vector<int>& get_chemin() const; //const pour pas modif chemin depuis render_area
    std::vector<voisin> get_voisins(int index) const;
    AlgoType get_current_algo() const ;

private:
    double bfs_time = 0.0;
    double dfs_time = 0.0;
    AlgoType current_algo = AlgoType::NONE;
    map* m_map;
    //vecteurs spécifiques aux algos
    std::vector<int> chemin_final_bfs; 
    std::vector<int> chemin_final_dfs;
 
};

#endif