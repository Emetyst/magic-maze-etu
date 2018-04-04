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
            Noeud(void* d);
            ~Noeud();
            void* donnee;
            std::vector<Noeud*> aretes;
        private:
    };
}

#endif
