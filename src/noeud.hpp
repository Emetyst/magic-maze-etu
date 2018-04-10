#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

namespace MMaze {

    class Noeud {
        public:
            Noeud(int t, int c);
            ~Noeud();
            CoordCase donnee;
            std::vector<Noeud*> aretes;
        private:
    };
}

#endif
