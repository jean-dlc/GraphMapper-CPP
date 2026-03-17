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
    this->type = type;
}
    



