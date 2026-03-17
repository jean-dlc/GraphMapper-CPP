
#ifndef MAP_HPP
#define MAP_HPP

#include "ivec2.hpp"
#include "Case.hpp"


class map {
private:
    std::vector<Case> grille;
    int largeur;
    int hauteur;
    int cell_size;

public:
    map();
    map(int l, int h);
    Case getCase(ivec2 vec);
    void set_casetype_in_grille(ivec2 vec, casetype type);

    int get_cell_size() const ;
    std::vector<Case> getgrille();
    // std::vector<Case>& setmap(); inutile je pense
    void generer_random_map(std::vector<Case> &grille);
};

#endif