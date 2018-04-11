#include "cell.hpp"

namespace MMaze {

    Cell::Cell(int v, Noeud* n) {
        priorite = v;
        noeud = n;
        v_next.push_back(nullptr);
    }

}