include "solver.hpp"
include "Case.hpp"

MapSolver::MapSolver(map* target_map) : m_map(target_map) {
    
}

void MapSolver::solve_tremaux() {

}

void MapSolver::solve_dijkstra() {

}

std::vector<voisin> MapSolver::get_voisins(int index) const {
    std::vector<voisin> liste_voisins;
    ivec2 position = m_map->getCase(index).getcoord();
    int x = position.x;
    int y = position.y;

    //verif 4 directions
    liste_voisins.clear();
    liste_voisins.push_back(voisin {getCase(ivec2 (x+1,y)), m_map->getCase(ivec2(x+1,y)).getcasetype()});//droite
    liste_voisins.push_back(voisin {getCase(ivec2 (x,y-1)), m_map->getCase(ivec2(x,y-1)).getcasetype()});//bas
    liste_voisins.push_back(voisin {getCase(ivec2 (x-1,y)), m_map->getCase(ivec2(x-1,y)).getcasetype()});//gauche
    liste_voisins.push_back(voisin {getCase(ivec2 (x,y+1)), m_map->getCase(ivec2(x,y+1)).getcasetype()});//haut

    return liste_voisins;
}