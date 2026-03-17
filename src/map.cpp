#include "map.hpp"
#include "Case.hpp"
#include <vector>



map::map(int l, int h)
    : largeur(l), hauteur(h), cell_size(30) 
{
    int nb =l*h;
    grille.reserve(nb);

    for(int i=0;i<nb;i++){
        int x= i%l;
        int y= i/l;

        bool visibilité = false;
        grille.emplace_back(ivec2(x, y), casetype::Vide, visibilité);
    }
}

map::map(): map(20,20){}


Case map::getCase(ivec2 vec){
    // float p = vec.x/this.cell_size + this.l *vec.y/this.cell_size;
    // int i = (int)p; 
    // return Grille[i];

    // version renvoie l'id dans la grille et pas les coord qui sont deja renvoyées par getCase
    int i = vec.x + (vec.y * largeur);
    return grille[i];
}


std::vector<Case> map::getgrille(){
    return grille;
}

// probablement inutile on modif case par case pas grille entière
// std::vector<Case>& map::setmap(){
//     return grille;
// }



// pas bon c'est pas un set et ca sert juste pour afficher et setcase va dans case.cpp
// void map::setCase(ivec2 vec){
//     float p = vec.x/this.cell_size + this.l *vec.y/this.cell_size;
//     int i = (int)p; 
//     return Grille[i];
// }

void map::set_casetype_in_grille(ivec2 vec, casetype type){
    int i = vec.x + (vec.y * largeur);
    
    // verif si index valide
    if (i >= 0 && i < (int)grille.size()) {
        grille[i].setcasetype(type);
    }
}

int map::get_cell_size() const {
    return cell_size;
}