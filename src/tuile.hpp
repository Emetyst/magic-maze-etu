#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "mur.hpp"
#include "melangeur.hpp"
#include "site.hpp"
#include "liste.hpp"
#include "unionfind.hpp"
#include "direction.hpp"
#include "graphe.hpp"

#include <fstream>
#include <string>
#include <vector>

namespace MMaze {
  class Tuile {

    public:
    
      Tuile(int id = 0, bool depart = false);
      void sauver_dans_fichier(std::string nom);
      void lire_dans_fichier(std::string nom);
      void placer_autre_site(const Type & t, const Couleur & c);
      void rotation_gauche();
      void rotation_droite();
      void construire_graphe(Graphe& g);
      bool mur(Mur m) const; //indique si deux cases voisines sont separees par un mur
      bool accessible(Case c); //indique si une case est accessible depuis les portes ou non
      friend std::ostream& operator<<(std::ostream& out, const Tuile& t); //affichage
      void afficher();

    private:
      std::vector<Site> vec_sites;
      std::vector<bool> vec_murs;
      int id_tuile;
      UnionFind classes_cases;

      void detruire_murs();
      void relier_sites(UnionFind& uf, std::vector<int> sites);
      void eliminer_impasses(UnionFind& uf, std::vector<int> sites);
      void reset_tuile();
      void update_classes_cases();
      void modifier_site(unsigned int pos, const Type & t, const Couleur & c);
      void afficher_horizontal(std::ostream& out, unsigned int i) const; //affichage
      void afficher_vertical(std::ostream& out, unsigned int i) const;
  };

} //end of namespace MMaze

#endif
