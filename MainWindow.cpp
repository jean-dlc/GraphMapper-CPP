#include "MainWindow.hpp"
#include <QMainWindow>
#include <QPainter>

MainWindow::MainWindow(Map* m, QWidget *parent){
    : QMainWindow(parent), map_pointer(m)
};


void MainWindow::paintEvent(QPaintEvent *event){
    
};