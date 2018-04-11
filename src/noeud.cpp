#include "noeud.hpp"

namespace MMaze {

    IdNoeud::IdNoeud(int t, int s) {
        tuile = t;
        site = s;
    }

    Noeud::Noeud(int t, int s) : id(IdNoeud(t, s)) {
        
    }

    Noeud::~Noeud() {
        
    }

    bool Noeud::est_voisin(Noeud* noeud) {
        for (unsigned int i = 0; i < voisins.size(); i++) {
            if (voisins[i].destination == noeud) return true;
        }
        return false;
    }

    void Noeud::ajouter_voisin(Direction dir, Noeud* dest) {
        voisins.push_back(Arete(dir, dest));
    }

    bool Noeud::compare_id(const IdNoeud& id_noeud) {
        return (id.tuile == id_noeud.tuile) && (id.site == id_noeud.site);
    }

    std::vector<Arete> Noeud::voisins_direction(Direction dir) {
        std::vector<Arete> liste_voisins;
        for (unsigned int i = 0; i < voisins.size(); i++) {
            if (voisins[i].direction == dir) {
                liste_voisins.push_back(voisins[i]);
            }
        }
        return liste_voisins;
    }
}