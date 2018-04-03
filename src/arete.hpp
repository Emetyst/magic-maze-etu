#ifndef ARETE_HPP
#define ARETE_HPP

#include "noeud.hpp"

namespace MMaze {
    class Arete {
        public:
            Arete(Noeud* n1, Noeud* n2);
            ~Arete();
        private:
            Noeud* source;
            Noeud* destination;
    };
}

#endif
