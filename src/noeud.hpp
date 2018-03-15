#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <iostream>

namespace MMaze {
    class Noeud {
        public:
            Noeud(int num_case);
            ~Noeud();
        private:
            int valeur;
    };
}

#endif
