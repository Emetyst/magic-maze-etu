#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include "arete.hpp"
#include "noeud.hpp"

#include <vector>

namespace MMaze {
    class Graphe {
        public:
            Graphe();
            ~Graphe();
        private:
            std::vector<Noeud*> nodes;
            std::vector<Arete*> edges;
    };
}

#endif
