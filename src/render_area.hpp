// ============================================================
// render_area — Zone de rendu Qt (hérite QWidget)
// Dessine la grille et le chemin via QPainter.
// Gère les clics souris pour placer des obstacles.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include <QWidget>
#include "map.hpp"
#include "Mapsolver.hpp"

class render_area : public QWidget
{
    Q_OBJECT
public:
    render_area(map* m, QWidget *parent = 0);
    ~render_area();

    //lien map affichage
    void set_map(map* m);

    void set_solver(Mapsolver* s) {
        solver_ptr = s;
        update(); // Redessine la zone pour afficher le chemin
    }

protected:
    void paintEvent(QPaintEvent *event) override;
    //clic faire case pleine
    void mousePressEvent(QMouseEvent *event) override;

private:
    
    map* map_ptr;
    Mapsolver* solver_ptr = nullptr;
};

#endif