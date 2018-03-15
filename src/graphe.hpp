#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include "arete.hpp"

namespace MMaze {
    class Graphe {
        public:
            Graphe();
            ~Graphe();
        private:
            Noeud* racine;
    };
}

#endif
