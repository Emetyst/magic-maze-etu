#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "tuile.hpp"

#include <sstream>

namespace MMaze {
  class Plateau {
    public:
      Plateau();
      ~Plateau();

      void etendre_plateau();

      void sauver_plateau_dans_dossier(std::string nom_dossier);

      void afficher_tuiles() {
        for (unsigned int i = 0; i < ensemble_tuiles.size(); i++) {
          ensemble_tuiles[i]->afficher();
        }
      }

    private:
      Melangeur* pioche_tuiles;
      std::vector<Tuile*> ensemble_tuiles;
      std::vector<int> tuiles_placees;
 
      int piocher();
  };
}

#endif