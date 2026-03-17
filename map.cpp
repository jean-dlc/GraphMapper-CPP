#include "map.hpp"
#include "Case.hpp"
#include <vector>
std::vector<Case> Grille;
int cell_size = 30;
map::map(int l, int h){ 
    float x,y;
    int nb =l*h;
    Grille.reserve(nb);
    for(int i=0;i<nb;i++){
        x= i%l*cell_size;
        y= i/l*cell_size;
        Grille.emplace_back(x, y, true, false);
    }
}
map::map(): map(20,20){}


Case map::getCase(vec2 vec){
    float p = vec.x/this.cell_size + this.l *vec.y/this.cell_size;
    int i = (int)p; 
    return Grille[i];
}
std::vector<Case> map::getmap(vec2 vec){
    return Grille;
}
std::vector<Case>& map::setmap(){
    return Grille;
}
Case& map::setCase(vec2 vec){
    float p = vec.x/this.cell_size + this.l *vec.y/this.cell_size;
    int i = (int)p; 
    return Grille[i];
}