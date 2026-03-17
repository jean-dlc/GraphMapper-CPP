#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>


class map;
class render_area;

class Window : public QMainWindow {
    Q_OBJECT
public:
   
    Window(map* m, QWidget *parent = nullptr);
    ~Window();

private:
    render_area* area; 
};

#endif