// ============================================================
// map — Grille de cases
// Stocke l'ensemble des cases dans un vector<Case> linéaire.
// Gère la génération aléatoire et l'indexation (x,y) -> id.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

#include "map.hpp"
#include "Case.hpp"
#include <vector>
#include <ctime>


map::map(int l, int h)
    : largeur(l), hauteur(h), cell_size(30) 
{
    int nb =l*h;
    grille.reserve(nb);

    for(int i=0;i<nb;i++){
        int x= i%l;
        int y= i/l;
        grille.emplace_back(ivec2(x, y), casetype::Vide);
    }
}

map::map(): map(20,20){}


Case map::getCase(ivec2 vec) const{
    // float p = vec.x/this.cell_size + this.l *vec.y/this.cell_size;
    // int i = (int)p; 
    // return Grille[i];

    // version renvoie l'id dans la grille et pas les coord qui sont deja renvoyées par getCase
    int i = vec.x + (vec.y * largeur);
    return grille[i];
}


std::vector<Case>& map::getgrille(){
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
// il faut ajouter un videur de case pour eviter conflit a deuxieme lancement
// permettre de modif la variable de chance case plein (20%)
void map::generer_random_map(){
    std::srand(std::time(nullptr));
    
    //def case start/end
    this->index_start = std::rand()%(grille.size()) ;
    grille[index_start].setcasetype(casetype::Start);

    this->index_end = std::rand() % (grille.size());
    while(this->index_end == this->index_start) { 
        this->index_end = std::rand() % (grille.size());
    }
    grille[index_end].setcasetype(casetype::End);   
   

    for(Case &c : grille){ // start end proteger par le setcasetype
        int val_aleatoire = std::rand()%100 ; 
        if(val_aleatoire<19){
            c.setcasetype(casetype::Plein);
        }
    
}
}

int map::get_id(ivec2 vec) const {
    int i = vec.x + (vec.y * largeur);
    return i;
}

int map::get_largeur() const {
    return largeur;
}

int map::get_hauteur() const {
    return hauteur;
}

int map::get_index_start() const {
    return index_start;
}

int map::get_index_end() const {
    return index_end;
}