#include "window.hpp"
#include "render_area.hpp"
#include "map.hpp"

Window::Window(map* m, QWidget *parent) : QMainWindow(parent) {
 // 1. Création du widget central qui contiendra tout
    main_widget = new QWidget(this);
    setCentralWidget(main_widget);

    // 2. Création du layout horizontal (Zone dessin à gauche | Boutons à droite)
    main_layout = new QHBoxLayout(main_widget);

    // 3. La zone de dessin
    area = new render_area(m, this);
    main_layout->addWidget(area, 1); // Le '1' permet à la zone de dessin de prendre l'espace

    // 4. Colonne de droite pour les boutons
    control_layout = new QVBoxLayout();
    
    btn_generate = new QPushButton("Générer Map", this);
    btn_start = new QPushButton("Start Algo", this);

    // On ajoute les boutons en haut de la colonne de droite
    control_layout->addWidget(btn_generate);
    control_layout->addWidget(btn_start);
    control_layout->addStretch(); // Pousse les boutons vers le haut

    // Dans le constructeur, après avoir créé btn_generate
// On stocke le pointeur de la map pour pouvoir l'utiliser plus tard
    this->m_ptr = m; 

    connect(btn_generate, &QPushButton::clicked, this, &Window::on_click_generer_random_map);

    main_layout->addLayout(control_layout);

    setWindowTitle("Projet Labyrinthe");
    resize(1000, 700);
}

Window::~Window(){

}

void Window::on_click_generer_random_map() {
    
    m_ptr->generer_random_map(m_ptr->getgrille());

    area->update(); 
}