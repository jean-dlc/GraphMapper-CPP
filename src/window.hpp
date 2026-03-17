#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QPushButton>    
#include <QHBoxLayout>     
#include <QVBoxLayout>     
#include <QWidget>
#include "render_area.hpp"
#include "map.hpp"

class map;
class render_area;

class Window : public QMainWindow {
    Q_OBJECT
public:
   
    Window(map* m, QWidget *parent = nullptr);
    ~Window();

private:
    render_area* area; 

    //boutons
    QPushButton *btn_generate;
    QPushButton *btn_start;
    
    //layouts pour l'orga
    QWidget *main_widget;
    QHBoxLayout *main_layout;
    QVBoxLayout *control_layout;
};

#endif