#ifndef MAPSOLVER_HPP
#define MAPSOLVER_HPP

#include "map.hpp"
#include <vector>

class MapSolver {
public:
    //pointer vers map
    MapSolver(map* target_map);

    void solve_tremaux();
    void solve_dijkstra();
    std::vector<int> get_voisins(int index) const;

private:
    map* m_map;
    //vecteurs spécifiques aux algos
    std::vector<int> traces_craie_tremaux; 
    std::vector<voisin> liste_voisins;
};

#endif