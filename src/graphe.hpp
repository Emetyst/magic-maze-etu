#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include "noeud.hpp"

namespace MMaze {
    class Graphe {
        public:
            Graphe();
            ~Graphe();
            void ajouter_noeud(Noeud* noeud);
            Noeud* rechercher_noeud(void* d);
            void supprimer_tete();
            void vider();
            void parcourir(Noeud* source, Noeud* destination);
        private:
            std::vector<Noeud*> noeuds;
    };
}

#endif
