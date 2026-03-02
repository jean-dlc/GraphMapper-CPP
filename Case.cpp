#include "Case.hpp"

Case::Case(vec2 posi, casetype type, bool visible){}


vec2 Case::getcoord()const{
    return posi;

}

bool Case::getvisible()const{
    return visible;
}

bool& Case::setvisible(){
    if(visible == true){
        return visible;
    }
}


casetype Case::getcasetype()const{
    return type;
}


