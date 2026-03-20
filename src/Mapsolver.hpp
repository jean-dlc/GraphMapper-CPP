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