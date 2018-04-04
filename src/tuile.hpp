#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "mur.hpp"
#include "melangeur.hpp"
#include "site.hpp"

#include <fstream>
#include <cstring>

namespace MMaze {

  class SiteOptions {
    public:
      unsigned int pos;
      Type type;
      Couleur couleur;

      SiteOptions(unsigned int p, Type t, Couleur c);
  };

  class TuileOptions {
    public:
      bool est_depart;
      std::vector<SiteOptions> vec;

      TuileOptions(bool depart = false);
  };

  class Tuile {

    public:

      Tuile(TuileOptions options = TuileOptions());

      //indique si deux cases voisines sont separees par un mur
      bool mur(Mur m) const;

      //indique si une case est accessible depuis les portes ou non
      bool accessible(Case c) const;

      //affichage
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t);

      void sauver_dans_fichier(std::string nom);

    private:
      std::vector<Site> vec_sites;
      std::vector<bool> vec_murs;

      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;
      void detruire_murs(TuileOptions options);
  };

} //end of namespace MMaze

#endif
