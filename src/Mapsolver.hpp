#ifndef MAPSOLVER_HPP
#define MAPSOLVER_HPP

#include "map.hpp"
#include <vector>

class Mapsolver {
public:
    //pointer vers map
    Mapsolver(map* target_map);

    void solve_tremaux();
    void solve_dijkstra();
    std::vector<voisin> get_voisins(int index) const;

private:
    map* m_map;
    //vecteurs spécifiques aux algos
    std::vector<int> traces_craie_tremaux; 
    std::vector<voisin> liste_voisins;
};

#endif