#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"
#include "site.hpp"
#include "mur.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>

namespace MMaze {

  class SiteBuildOptions {
    public:
      unsigned int pos;
      Type type;
      Couleur couleur;

      SiteBuildOptions(unsigned int p, Type t, Couleur c);
  };

  class TuileBuildOptions {
    public:
      bool estDepart;
      std::vector<SiteBuildOptions> sites;

      TuileBuildOptions(bool depart = false);
  };

  class Tuile {

    public:
      Tuile(TuileBuildOptions options = TuileBuildOptions());
      ~Tuile();

      //indique si deux cases voisines sont separees par un mur
      bool mur(Mur m) const;

      //indique si une case est accessible depuis les portes ou non
      bool accessible(Case c) const;

      //affichage
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t);

      void save_to_file(std::string filename);

    private:
      std::vector<Site> tab_sites;
      std::vector<bool> tab_murs;

      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;

      void detruire_murs(TuileBuildOptions options);
  };

} //end of namespace MMaze

#endif