// ============================================================
// ivec2 — Vecteur 2D entier
// Struct utilitaire représentant une position (x, y) sur la grille.
// Surcharge des opérateurs arithmétiques et de flux.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================


#pragma once

#ifndef IVEC2_HPP

#define IVEC2_HPP

#include <iostream>


/** A 2D vector */
struct ivec2
{
    /** x coordinate */
    int x;
    /** y coordinate */
    int y;

    /** Constructor vec (0,0) */
    ivec2();
    /** Constructor vec (x,y) */
    ivec2(int x_param,int y_param);

};



/** Scalar product */
int dot(ivec2 const& v0,ivec2 const& v1);




/** Print the content of a vector on the command line */
std::ostream& operator<<(std::ostream& sout,ivec2 const& m);

/** Vectorial sum */
ivec2& operator+=(ivec2& lhs,ivec2 const& rhs);
/** Vectorial difference */
ivec2& operator-=(ivec2& lhs,ivec2 const& rhs);
/** Multiplication by a scalar */
ivec2& operator*=(ivec2& v,float s);
/** Division by a scalar */
ivec2& operator/=(ivec2& v,float s);

ivec2& operator*=(ivec2& v,int s);
/** Division by a scalar */
ivec2& operator/=(ivec2& v,int s);

/** Vectorial sum */
ivec2 operator+(ivec2 const& v0,ivec2 const& v1);
/** Vectorial difference */
ivec2 operator-(ivec2 const& v0,ivec2 const& v1);
/** Multiplication with a scalar */
ivec2 operator*(ivec2 const& v0,float s);
/** Multiplication with a scalar (left) */
ivec2 operator*(float s,ivec2 const& v0);
/** Division by a scalar */
ivec2 operator/(ivec2 const& v0,float s);




#endif