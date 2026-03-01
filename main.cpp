#include VEC2_HPP
#include <unordered_map>
#include <iostream>

std::unordered_map<vec2, int> Grille;
Grille.reserve(400);  //lancement du jeu permet de gagner en efficacité sans avoir a réalouer la grille
