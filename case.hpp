#ifndef CASE_HPP
#define CASE_HPP

#include <unordered_map>
#include <vector>
#include "vec2.hpp"

class case 
{   
    public :
        case();
        case(vect2 (x,y), bool vide, bool visible);

        vect2 getcoord() const;
        bool getvide() const;
        bool getvisible() const ; 

        bool& setvisible();


    private : 
        int x;
        int y;
        bool vide ;
};


