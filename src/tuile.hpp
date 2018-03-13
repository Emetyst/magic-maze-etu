#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"
#include "site.hpp"
#include "mur.hpp"

#include <vector>
#include <iostream>

namespace MMaze {

  class Tuile {

    public:
      Tuile(bool depart = false);

      //indique si deux cases voisines sont separees par un mur
      bool mur(Mur m) const;

      //indique si une case est accessible depuis les portes ou non
      bool accessible(Case c) const;

      //affichage
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t);

    private:
      std::vector<Site> tab_sites;
      Melangeur* couleurs_portes;




      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;
  };

} //end of namespace MMaze

#endif
