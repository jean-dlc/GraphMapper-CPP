#include "map.hpp"
#include "Case.hpp"
#include <vector>
std::vector<Case> Grille;
map::map(int l, int h){ 
    float x,y;
     int nb =l*h;
    Grille.reserve(nb);
    for(int i=0;i<nb;i++){
        x= i%l;
        y= i/l;
        Grille.emplace_back(x, y, true, false);
    }
}
map::map(): map(20,20){}