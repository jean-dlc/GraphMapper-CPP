#include <QApplication>
#include "MainWindow.hpp"
#include "map.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 1. On crée l'objet Map (les données)
    Map maMap; 

    // 2. On crée la fenêtre en lui passant l'ADRESSE de la map (&)
    MainWindow w(&maMap); 
    
    w.show(); // On affiche la fenêtre
    return a.exec(); // On lance la boucle d'événements Qt
}