# Projet Labyrinthe — Plateforme d'exploration de graphes en C++

> Projet C++ avec interface Qt5 — Exploration de grille par BFS et DFS  
> Réalisé dans le cadre du cours de programmation C++ (4IMI, 2025-2026)

Auteurs : Jean DE LA CHAPELLE et Arthus LUCIC
---

##  Lancement du projet

```bash
chmod +x run.sh
./run.sh
```


## Description

Ce projet implémente une **plateforme interactive d'exploration de graphes** sous forme de grille 2D.  
Une carte est générée aléatoirement avec des cases libres, des obstacles, un point de départ (vert) et une arrivée (rouge).  
Deux algorithmes de recherche de chemin sont implémentés et visualisables en temps réel via une interface Qt5 :

- **BFS** (Breadth-First Search) — garantit le chemin le plus court
- **DFS** (Depth-First Search) — explore en profondeur avec backtracking

L'utilisateur peut également **dessiner ses propres murs** en cliquant sur la grille.

---

## Structure du projet

```
2526-4imi-projetscpp-jean_arthus/
├── src/
│   ├── main.cpp          # Point d'entrée, instanciation de la map et de la fenêtre
│   ├── ivec2.hpp/.cpp    # Vecteur 2D entier avec surcharge d'opérateurs
│   ├── Case.hpp/.cpp     # Modèle d'une case (coordonnées + type)
│   ├── map.hpp/.cpp      # Grille de cases, génération aléatoire
│   ├── Mapsolver.hpp/.cpp# Algorithmes BFS et DFS, calcul du chemin
│   ├── render_area.hpp/.cpp # Widget Qt — rendu visuel de la grille
│   └── window.hpp/.cpp   # Fenêtre principale Qt, gestion des boutons et états
├── projet.pro            # Fichier de projet qmake
├── Makefile              # Makefile généré par qmake
├── run.sh                # Script de lancement rapide
└── README.md
```

---
## 🖥️ Utilisation

1. **Lancer le programme** : une fenêtre s'ouvre avec une grille vide de 20×20
2. **Générer une map** : cliquer sur `Générer Map` — place aléatoirement un départ (vert), une arrivée (rouge) et des obstacles (~19% des cases)
3. **Lancer BFS** : cliquer sur `Start Algo BFS` — trace le chemin le plus court en bleu avec numérotation des étapes
4. **Lancer DFS** : cliquer sur `Start Algo DFS` — trace un chemin par exploration en profondeur
5. **Dessiner des murs** : cliquer directement sur une case de la grille pour la bloquer (case noire)
6. **Réinitialiser** : cliquer sur `Reset` pour repartir de zéro

### Légende des couleurs

| Couleur | Signification |
|---------|---------------|
| ⬜ Blanc | Case libre (Vide) |
| ⬛ Noir | Obstacle (Plein) |
| 🟩 Vert | Point de départ (Start) |
| 🟥 Rouge | Point d'arrivée (End) |
| 🟦 Bleu (numéroté) | Chemin trouvé |

---

## 🧠 Algorithmes implémentés

### BFS — Breadth-First Search
- Utilise une `std::queue<int>` pour explorer niveau par niveau
- Garantit le **chemin le plus court** en nombre de cases
- Complexité : **O(V + E)** où V = nombre de cases, E = nombre d'arêtes (voisins)
- Le chemin est reconstruit par remontée du tableau `parent[]`

### DFS — Depth-First Search
- Utilise un `std::vector<int>` comme pile explicite avec **backtracking**
- Ne garantit pas le chemin le plus court, mais trouve un chemin s'il existe
- Complexité : **O(V + E)**
- Implémentation itérative (évite le débordement de pile sur grande grille)

### Comparaison

| Critère | BFS | DFS |
|---------|-----|-----|
| Chemin optimal | Oui | Non garanti |
| Mémoire | Plus élevée (file) | Plus faible (pile) |
| Exploration | En largeur | En profondeur |
| Cas idéal | Chemin court à trouver | Labyrinthe profond |

---

## 🏗️ Choix d'architecture

Le projet suit une architecture **MVC (Modèle-Vue-Contrôleur)** :

- **Modèle** : `map`, `Case`, `ivec2`, `Mapsolver` — logique pure, sans Qt
- **Vue** : `render_area` — hérite de `QWidget`, rendu graphique via `QPainter`
- **Contrôleur** : `Window` — gère les signaux Qt, les états applicatifs (`AppState`) et orchestre modèle ↔ vue

Les états de l'application sont modélisés par une `enum class AppState` permettant d'activer/désactiver les boutons de façon cohérente.

---

## 🔧 Fonctionnalités C++ illustrées

- **Surcharge d'opérateurs** : `ivec2` surcharge `+`, `-`, `*`, `/`, `<<`, `+=`, `-=`
- **Encapsulation** : attributs privés avec getters dans `map`, `Case`, `Mapsolver`
- **STL** : `std::vector`, `std::queue`, `std::chrono`
- **Enum class** : `casetype`, `AlgoType`, `AppState`
- **`override`** : `paintEvent` et `mousePressEvent` dans `render_area`
- **`const`** : méthodes constantes sur les accesseurs
- **Séparation Modèle/Vue** : `Mapsolver` ne connaît pas Qt

---


