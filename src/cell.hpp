#ifndef CELL_HPP
#define CELL_HPP

#include "noeud.hpp"

#include <vector>

namespace MMaze {
    class Cell {
        public:
            int priorite;
            Noeud* noeud;
            std::vector<Cell*> v_next;

            Cell(int v, Noeud* n = nullptr);
    };
}

#endif
