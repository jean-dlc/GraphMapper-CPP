// ============================================================
// render_area — Zone de rendu Qt (hérite QWidget)
// Dessine la grille et le chemin via QPainter.
// Gère les clics souris pour placer des obstacles.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

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

void render_area::paintEvent(QPaintEvent*) {
    if (!map_ptr) return;
    
    QPainter painter(this);
    
    //récupère taille des cases et la grille
    int cs = map_ptr->get_cell_size();
    const std::vector<Case>& grille = map_ptr->getgrille();

    for (const Case &c : grille) {
        ivec2 pos = c.getcoord();
        
        // Couleur selon le type de case
        if (c.getcasetype() == casetype::Plein) {
            painter.setBrush(Qt::black);
        } 
        else if (c.getcasetype() == casetype::Start) {
            painter.setBrush(Qt::green); // Départ en Vert
        } 
        else if (c.getcasetype() == casetype::End) {
            painter.setBrush(Qt::red);   // Arrivée en Rouge
        } 
        else {
            painter.setBrush(Qt::white); // Vide = Blanc
        }

        //posi * taille pixel
        painter.drawRect(pos.x * cs, pos.y * cs, cs, cs);
    }

    if (solver_ptr) {
        const std::vector<int>& chemin = solver_ptr->get_chemin();

        painter.setBrush(QColor(0, 120, 255, 150)); // couleur cases chemin
        painter.setPen(Qt::black); // couleur chiffres chemin

        QFont font = painter.font();
        font.setPointSize(8);
        painter.setFont(font);

        for (int i = 0; i < (int)chemin.size(); i++) {

            int id_case = chemin[i];

            //skip start/end pour la couleur BLEUE
            if (id_case == map_ptr->get_index_start() ||
                id_case == map_ptr->get_index_end()) {
                continue;
            }

        int x = id_case % map_ptr->get_largeur();
        int y = id_case / map_ptr->get_largeur();

        //carré bleu
        painter.drawRect(x * cs + 2, y * cs + 2, cs - 4, cs - 4);

        //numéro par-dessus
        painter.drawText(
            x * cs, y * cs, cs, cs,
            Qt::AlignCenter,
            QString::number(i)
        );
    }
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