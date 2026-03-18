
#ifndef MAP_HPP
#define MAP_HPP

#include "ivec2.hpp"
#include "Case.hpp"

struct voisin {
    int index;
    casetype type;
};


class map {
private:
    std::vector<Case> grille;
    int largeur;
    int hauteur;
    int cell_size;
    int index_start;
    int index_end;

public:
    map();
    map(int l, int h);
    Case getCase(ivec2 vec);
    void set_casetype_in_grille(ivec2 vec, casetype type);
    int get_id(ivec2 vec) const;
    int get_largeur() const ;
    int get_hauteur() const ;
    int get_index_start() const ;
    int get_index_end() const ;
    int get_cell_size() const ;
    std::vector<Case>& getgrille(); //doute sur le nom  verif a faire sur const
    // std::vector<Case>& setmap(); inutile je pense
    void generer_random_map(std::vector<Case> &grille);
};

#endif