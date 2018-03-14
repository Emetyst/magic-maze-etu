#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "tuile.hpp"

namespace MMaze {
    class Plateau {
        private:
			Plateau();
			~Plateau();

        public:
			Melangeur* pioche_tuiles;
    };
}

#endif