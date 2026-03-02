#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include "map.hpp"

class MainWindow: public QMainWindow{

    private :
        Map* map_pointer ;

    public:
        MainWindow(Map* map_pointeur, QWidget *parent = nullptr);

        void paintEvent(QPaintEvent *event) override;

};

#endif

