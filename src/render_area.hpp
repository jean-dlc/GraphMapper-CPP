#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include <QWidget>
#include "map.hpp"

class render_area : public QWidget
{
    Q_OBJECT
public:
    render_area(map* m, QWidget *parent = 0);
    ~render_area();

    //lien map affichage
    void set_map(map* m);

protected:
    void paintEvent(QPaintEvent *event) override;
    //clic faire case pleine
    void mousePressEvent(QMouseEvent *event) override;

private:
    
    map* map_ptr;
};

#endif