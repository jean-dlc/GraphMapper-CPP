// ============================================================
// Window — Fenêtre principale Qt (hérite QMainWindow)
// Contrôleur central : orchestre map, Mapsolver et render_area.
// Gère les états (AppState) et les interactions boutons.
// ------------------------------------------------------------
// Auteurs : Jean de la Chapelle, Arthus Lucic
// Date    : 20/03/2026
// ============================================================

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

enum class AppState {
    Initial,         // Juste après le lancement
    MapGeneree,      // La carte est prête, on attend un algo
    CheminAffiche    // Un chemin est affiché on attend reset ou l'autre algo
};

class Window : public QMainWindow {
    Q_OBJECT
public:
   
    Window(map* m, QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_click_generer_random_map(); //clique btn lance fct dans map.cpp
    void on_click_start_algo_BFS(); //clique btn lance fct dans mapsolver.cpp
    void on_click_start_algo_DFS(); //clique btn lance fct dans mapsolver.cpp
    void updateButtons(); //active/desactive les boutons selon l'etat de l'appli
    void on_click_reset(); //reset la map et les boutons

private:
    AppState current_state = AppState::Initial;
    render_area* area; 
    std::unique_ptr<Mapsolver> solver_ptr;
    map* m_ptr;

    //boutons
    QPushButton *btn_generate;
    QPushButton *btn_start_BFS;
    QPushButton *btn_start_DFS; 
    QPushButton *btn_reset;
    //layouts pour l'orga
    QWidget *main_widget;
    QHBoxLayout *main_layout;
    QVBoxLayout *control_layout;
};

#endif