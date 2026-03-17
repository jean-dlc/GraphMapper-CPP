#include "render_area.hpp"
#include <QPainter>
#include <QMouseEvent>


render_area::render_area(map* m, QWidget *parent)
    : QWidget(parent), map_ptr(m)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    
}

render_area::~render_area()
{}

// void render_area::set_map(Map* m) {
//     map_ptr = m;
//     update(); 
// }

void render_area::paintEvent(QPaintEvent*) {
    if (!map_ptr) return;
    
    QPainter painter(this);
    
    //récupère taille des cases et la grille
    int cs = map_ptr->get_cell_size();
    const std::vector<Case>& grille = map_ptr->getgrille();

    for (const Case &c : grille) {
        ivec2 pos = c.getcoord();
        
        //Couleur : Plein = Noir, Vide = Blanc
        if (c.getcasetype() == casetype::Plein) {
            painter.setBrush(Qt::black);
        } else {
            painter.setBrush(Qt::white);
        }

        //posi * taille pixel
        painter.drawRect(pos.x * cs, pos.y * cs, cs, cs);
    }
}

//dessin murs
void render_area::mousePressEvent(QMouseEvent *event) {
    if (!map_ptr) return;

    int cs = map_ptr->get_cell_size();
    
    //transforme pixels en index de case (x, y)
    int x = event->pos().x() / cs;
    int y = event->pos().y() / cs;

    //modifie la case dans la map
    map_ptr->set_casetype_in_grille(ivec2(x, y), casetype::Plein);

    
    update();
}