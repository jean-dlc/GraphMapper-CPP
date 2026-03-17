#include "MainWindow.hpp"
#include <QMainWindow>
#include <QPainter>

MainWindow::MainWindow(Map* m, QWidget *parent):{
     QMainWindow(parent), map_pointer(m)
};


void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    cell_size = map_pointer->get_cell_size();
    const std::vector<Case>& grille = map_pointer->getGrille();

    for (const Case &c : grille) {
        ivec2 pos = c.getposi();
        
        //choix de la couleur (Plein = Noir, Vide = Blanc)
        if (c.getcasetype() == casetype::Plein) {
            painter.setBrush(Qt::black);
        } else {
            painter.setBrush(Qt::white);
        }

        // dessin du rectangle
    
        painter.drawRect(pos.x * cs, pos.y * cs, cs, cs);
    }
}