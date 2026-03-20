// ============================================================
// map — Grille de cases
// Stocke l'ensemble des cases dans un vector<Case> linéaire.
// Gère la génération aléatoire et l'indexation (x,y) -> id.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

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
    int index_start = -1;
    int index_end   = -1;

public:
    map();
    map(int l, int h);
    Case getCase(ivec2 vec) const;
    void set_casetype_in_grille(ivec2 vec, casetype type);
    int get_id(ivec2 vec) const;
    int get_largeur() const ;
    int get_hauteur() const ;
    int get_index_start() const ;
    int get_index_end() const ;
    int get_cell_size() const ;
    std::vector<Case>& getgrille() ; //doute sur le nom  verif a faire sur const
    // std::vector<Case>& setmap(); inutile je pense
    void generer_random_map();
};

#endif