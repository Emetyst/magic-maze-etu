#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "tuile.hpp"

#include <sstream>

namespace MMaze {
  class Plateau {
    public:
      Plateau();
      ~Plateau();

      void etendre_plateau(IdNoeud id);

      void sauver_plateau_dans_dossier(std::string nom_dossier);

      void afficher_tuiles();

      void afficher_tuiles_placees();

      void afficher_graphe();

      Graphe g;

    private:
      Melangeur* pioche_tuiles;
      std::vector<Tuile*> ensemble_tuiles;
      std::vector<int> tuiles_placees;

      std::vector<bool> objectifs_trouves;
      std::vector<bool> sorties_trouvees;
 
      int piocher();
      void check_objectif(int indice_pioche);
  };
}

#endif