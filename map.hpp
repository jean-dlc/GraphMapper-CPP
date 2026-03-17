
class map {
private:
    std::vector<Case> grille;
    int largeur;
    int hauteur;
    int cell_size;

public:
    map();
    map(int l, int h);
    Case getCase();
};