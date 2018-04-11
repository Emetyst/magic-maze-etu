#ifndef NOEUD_HPP
#define NOEUD_HPP

#include "direction.hpp"
#include "arete.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

namespace MMaze {

    class Arete;
    
    class IdNoeud {
        public:
            IdNoeud(int t, int s);

            int tuile;
            int site;
    };

    class Noeud {
        public:
            Noeud(int t, int s);
            ~Noeud();

            bool est_voisin(Noeud* noeud);
            void ajouter_voisin(Direction dir, Noeud* dest);
            bool compare_id(const IdNoeud& id_noeud);
            std::vector<Arete> voisins_direction(Direction dir);

            IdNoeud id;
            std::vector<Arete> voisins;
    };
}

#endif
