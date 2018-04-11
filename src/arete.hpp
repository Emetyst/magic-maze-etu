#ifndef ARETE_HPP
#define ARETE_HPP

#include "direction.hpp"
#include "noeud.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

namespace MMaze {

    class Noeud;

    class Arete {
        public:
            Arete(Direction dir, Noeud* dest);

            Direction direction;
            Noeud* destination;
    };
}

#endif
