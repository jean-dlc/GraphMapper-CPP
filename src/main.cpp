// ============================================================
// main — Point d'entrée de l'application
// Initialise QApplication, instancie map et Window.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

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