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
    
      Tuile(int id = 0, bool depart = false);

      //indique si deux cases voisines sont separees par un mur
      bool mur(Mur m) const;

      //indique si une case est accessible depuis les portes ou non
      bool accessible(Case c) const;

      //affichage
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t);

      void modifier_site(unsigned int pos, const Type & t, const Couleur & c);
      void placer_autre_site(const Type & t, const Couleur & c);
      void sauver_dans_fichier(std::string nom);

      void rotation_gauche();
      void rotation_droite();

    private:
      std::vector<Site> vec_sites;
      std::vector<bool> vec_murs;
      int id_tuile;

      //affichage
      void afficher_horizontal(std::ostream& out, unsigned int i) const;
      void afficher_vertical(std::ostream& out, unsigned int i) const;
      void detruire_murs();

  };

} //end of namespace MMaze

#endif
