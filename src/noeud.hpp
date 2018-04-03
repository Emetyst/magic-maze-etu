#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <iostream>

namespace MMaze {
    class Noeud {
        public:
            Noeud();
            ~Noeud();
        private:
            void* data;
    };
}

#endif
