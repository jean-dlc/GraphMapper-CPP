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

private slots:
    void on_click_generer_random_map(); //clique btn lance fct dans map.cpp


private:
    render_area* area; 

    map* m_ptr;

    //boutons
    QPushButton *btn_generate;
    QPushButton *btn_start;
    
    //layouts pour l'orga
    QWidget *main_widget;
    QHBoxLayout *main_layout;
    QVBoxLayout *control_layout;
};

#endif