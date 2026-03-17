
#include "ivec2.hpp"

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
    void set_case_in_grille(ivec2 vec, casetype type);

    std::vector<Case> getmap();
    // std::vector<Case>& setmap(); inutile je pense
};