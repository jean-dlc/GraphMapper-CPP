#ifndef CASE_HPP
#define CASE_HPP

#include <unordered_map>
#include <vector>
#include "vec2.hpp"

enum class casetype{Vide, Plein, Start, End};


class Case{   
    public :
        Case(vec2 posi, casetype type,bool visible);

        vec2 getcoord() const;
        casetype getcasetype() const;
        bool getvisible() const ; 

        bool& setvisible();


    private : 
        vec2 posi;
        bool visible;
        casetype type;
};
#endif

