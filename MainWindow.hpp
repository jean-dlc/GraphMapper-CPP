#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include "Map.hpp"

class affi: public QMainWindow{

    private :
        int* pointer ;

    public:
        void paintEvent(QPaintEvent *event) const override;

};

#endif

