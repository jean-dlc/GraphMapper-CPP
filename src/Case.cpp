// ============================================================
// Case — Cellule élémentaire de la grille
// Contient une position (ivec2) et un type (casetype).
// Protège les cases Start/End contre l'écrasement accidentel.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

#include "Case.hpp"

Case::Case(ivec2 posi, casetype type)
: posi(posi), type(type)
{}


ivec2 Case::getcoord()const{
    return posi;

}


casetype Case::getcasetype()const{
    return type;
}

void Case::setcasetype(casetype type){
    if(this->type != casetype::End && this->type != casetype::Start){ //empeche modif start/end dans la boucle de generation aleatoire map
        this->type = type;
    }
    else{
        if(type == casetype::End){
            this->type = casetype::End;
        }
        if(type== casetype::Start){
            this->type = casetype::Start;
        }
    }
}

void Case::setcasetype_reset(casetype type){//uniquement pour reset map
    this->type = type; 
}
    



