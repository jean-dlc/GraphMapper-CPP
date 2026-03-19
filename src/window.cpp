#include "window.hpp"
#include "render_area.hpp"
#include "map.hpp"
#include "Mapsolver.hpp"

Window::Window(map* m, QWidget *parent) : QMainWindow(parent) {
 //widget central conteneur
    main_widget = new QWidget(this);
    setCentralWidget(main_widget);

    // layout horizontal
    main_layout = new QHBoxLayout(main_widget);

    //zone de dessin
    area = new render_area(m, this);
    main_layout->addWidget(area, 1); // Le '1' permet à la zone de dessin de prendre l'espace

    //Colonne de droite pour les boutons
    control_layout = new QVBoxLayout();
    
    btn_generate = new QPushButton("Générer Map", this);
    btn_start_BFS = new QPushButton("Start Algo BFS", this);
    btn_start_DFS = new QPushButton("Start Algo DFS", this);
    btn_reset = new QPushButton("Reset", this); 

    //boutons en haut de la colonne de droite
    control_layout->addWidget(btn_generate);
    control_layout->addWidget(btn_start_BFS);
    control_layout->addWidget(btn_start_DFS);
    control_layout->addWidget(btn_reset);

    control_layout->addStretch(); // Pousse les boutons vers le haut

// pointeur de la map et mapsolver
    this->m_ptr = m; 
    solver_ptr = new Mapsolver(m_ptr);

    connect(btn_generate, &QPushButton::clicked, this, &Window::on_click_generer_random_map);
    connect(btn_start_BFS, &QPushButton::clicked, this, &Window::on_click_start_algo_BFS);
    connect(btn_start_DFS, &QPushButton::clicked, this, &Window::on_click_start_algo_DFS);
    connect(btn_reset, &QPushButton::clicked, this, &Window::on_click_reset);

    main_layout->addLayout(control_layout);

    setWindowTitle("Projet Labyrinthe");
    resize(1000, 700);
    updateButtons();
}

Window::~Window(){

}

void Window::on_click_generer_random_map() {
    
    m_ptr->generer_random_map(m_ptr->getgrille());
    current_state = AppState::MapGeneree;
    updateButtons();

    area->update(); 
}

void Window::on_click_start_algo_BFS() {
    solver_ptr->solve_BFS();
    current_state = AppState::CheminAffiche;
    updateButtons();

    area->set_solver(solver_ptr); 
}

void Window::on_click_start_algo_DFS() {
    solver_ptr->solve_DFS();
    current_state = AppState::CheminAffiche;
    updateButtons();
    area->set_solver(solver_ptr); 
}


void Window::updateButtons() {
    if (!btn_generate || !btn_start_BFS || !btn_start_DFS || !btn_reset || !solver_ptr) {
        printf("ERREUR : Un des pointeurs est NULL !\n");
        return; 
    }
    switch (current_state) {
        case AppState::Initial:
            btn_generate->setEnabled(true);
            btn_start_BFS->setEnabled(false);
            btn_start_DFS->setEnabled(false);
            btn_reset->setEnabled(false);
            break;

        case AppState::MapGeneree:
            btn_generate->setEnabled(false); 
            btn_start_BFS->setEnabled(true);
            btn_start_DFS->setEnabled(true);
            btn_reset->setEnabled(true);
            break;

        case AppState::CheminAffiche:
            btn_generate->setEnabled(false);
            // On bloque l'algo qui vient d'être fait (ex: si c'était BFS, on laisse DFS)
            btn_start_BFS->setEnabled(solver_ptr->get_current_algo() != AlgoType::BFS);
            btn_start_DFS->setEnabled(solver_ptr->get_current_algo() != AlgoType::DFS);
            btn_reset->setEnabled(true);
            break;
    }
}

void Window::on_click_reset() {
    solver_ptr->reset(); 
    current_state = AppState::Initial;
    updateButtons();
    area->set_solver(solver_ptr); 
}