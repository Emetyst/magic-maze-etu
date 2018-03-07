#ifndef SITE_HPP
#define SITE_HPP

#include "case.hpp"
#include "couleurs.hpp"

namespace MMaze {
    enum Type {
        AUCUN,
        PORTE,
        OBJECTIF,
        SORTIE,
        POINT_DEPART
    };

    class Site : public Case {
        private:
            Type type;
            Couleur couleur;

        public:
            Site(unsigned int li, unsigned int col, Couleur c = AUCUNE, Type t = AUCUN);
            explicit Site(unsigned int index, Couleur c, Type t);
    };
}

#endif