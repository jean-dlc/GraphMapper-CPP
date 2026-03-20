// ============================================================
// Case — Cellule élémentaire de la grille
// Contient une position (ivec2) et un type (casetype).
// Protège les cases Start/End contre l'écrasement accidentel.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

#ifndef CASE_HPP
#define CASE_HPP

#include <unordered_map>
#include <vector>
#include "ivec2.hpp"

enum class casetype{Vide, Plein, Start, End};


class Case{   
    public :
        Case(ivec2 posi, casetype type);

        ivec2 getcoord() const;
        casetype getcasetype() const;

        void setcasetype(casetype type);
        void setcasetype_reset(casetype type); 
        

    private : 
        ivec2 posi;
        casetype type;
};
#endif

