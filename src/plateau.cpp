#include "plateau.hpp"

namespace MMaze {
  Plateau::Plateau() {
    int MAX_TUILES = 24;
    ensemble_tuiles.resize(MAX_TUILES, nullptr);
    int id = 0;

    // Ajout tuile depart
    ensemble_tuiles[id] = new Tuile(0, true);
    id++;

    Type tab_types[2] = { OBJECTIF, SORTIE };
    Couleur tab_couleurs[4] = { JAUNE, VERT, ORANGE, VIOLET };

    // Ajout tuiles objectifs et sorties
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 4; j++) {
        ensemble_tuiles[id] = new Tuile(id);
        ensemble_tuiles[id]->placer_autre_site(tab_types[i], tab_couleurs[j]);
        id++;
      }
    }

    for (int i = id; i < MAX_TUILES; i++) {
      ensemble_tuiles[id] = new Tuile(id);
      id++;
    }

    pioche_tuiles = new Melangeur(sizeof(int));

    for (int i = 1; i < MAX_TUILES; i++) {
      pioche_tuiles->inserer(&i);
    }
  }

  Plateau::~Plateau() {
    for (unsigned int i = 0; i < ensemble_tuiles.size(); i++) {
      delete ensemble_tuiles[i];
    }
    delete pioche_tuiles;
  }

  void Plateau::etendre_plateau() {
    tuiles_placees.push_back(piocher());

  }

  int Plateau::piocher() {
    int pioche;
    pioche_tuiles->retirer(&pioche);
    return pioche;
  }

  void Plateau::sauver_plateau_dans_dossier(std::string nom_dossier) {
    for (unsigned int i = 0; i < ensemble_tuiles.size(); i++) {
      std::stringstream ss;
      ss << nom_dossier << "tuile_" << i << ".txt";
      ensemble_tuiles[i]->sauver_dans_fichier(ss.str());
    }
  }
}
