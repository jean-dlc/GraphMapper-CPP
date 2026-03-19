#ifndef CASE_HPP
#define CASE_HPP

#include <unordered_map>
#include <vector>
#include "ivec2.hpp"

enum class casetype{Vide, Plein, Start, End};


class Case{   
    public :
        Case(ivec2 posi, casetype type,bool visible);

        ivec2 getcoord() const;
        casetype getcasetype() const;
        bool getvisible() const ; 

        void setvisible();
        void setcasetype(casetype type);
        void setcasetype_reset(casetype type); 
        

    private : 
        ivec2 posi;
        bool visible;
        casetype type;
};
#endif

