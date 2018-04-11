#include "arete.hpp"

namespace MMaze {

    Arete::Arete(Direction dir, Noeud* dest) {
        direction = dir;
        destination = dest;
    }
}