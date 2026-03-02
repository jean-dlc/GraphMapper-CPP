#include "Case.hpp"

Case::Case(vec2 posi, casetype type, bool visible)
: posi(posi), type(type), visible(visible)
{}


vec2 Case::getcoord()const{
    return posi;

}

bool Case::getvisible()const{
    return visible;
}

void Case::setvisible(bool v){
    if(visible == true){
        visible = v;
    }
}


casetype Case::getcasetype()const{
    return type;
}


