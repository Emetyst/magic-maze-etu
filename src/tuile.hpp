#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "mur.hpp"
#include "melangeur.hpp"
#include "site.hpp"

#include <fstream>
#include <cstring>
#include <vector>

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

      void sauver_dans_fichier(std::string nom);

    private:
      std::vector<Site> vec_sites;
      std::vector<bool> vec_murs;

      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;
      void detruire_murs();

      void modifier_site(unsigned int pos, const Type & t, const Couleur & c);
  };

} //end of namespace MMaze

#endif
