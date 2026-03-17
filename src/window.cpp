#include "window.hpp"
#include "render_area.hpp"
#include "map.hpp"

Window::Window(map* m, QWidget *parent) : QMainWindow(parent) {
    //zone de dessin
    area = new render_area(m, this);

    //affiche centre
    setCentralWidget(area); 

    setWindowTitle("Projet");
    resize(800, 600);
}

Window::~Window() {
    // Pas besoin de 'delete area', Qt s'en occupe car 'this' est son parent
}