#ifndef SITE_HPP
#define SITE_HPP

#include "case.hpp"
#include "couleurs.hpp"

namespace MMaze {
    class Site : public Case {
        private:
            Couleur porte;
            Couleur objectif;
            Couleur sortie;
            Couleur point_depart;

        public:
            Site(unsigned int l, unsigned int c);
            explicit Site(unsigned int index);
    };
}

#endif