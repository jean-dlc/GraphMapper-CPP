#include <QApplication>
#include "window.hpp" 
#include "map.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    map maMap; 

    Window w(&maMap); 
    
    w.show(); 
    return a.exec(); 
}