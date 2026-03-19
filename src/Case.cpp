#include "Case.hpp"

Case::Case(ivec2 posi, casetype type, bool visible)
: posi(posi), type(type), visible(visible)
{}


ivec2 Case::getcoord()const{
    return posi;

}

bool Case::getvisible()const{
    return visible;
}

void Case::setvisible(){
    visible = true; // une case devient visible jusqu'a reinitialisation du jeu
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

void Case::setcasetype_reset(casetype type){
    this->type = type; 
}
    



