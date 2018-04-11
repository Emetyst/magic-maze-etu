#include "plateau.hpp"

namespace MMaze {
  Plateau::Plateau() {
    objectifs_trouves.resize(4, false);
    sorties_trouvees.resize(4, false);
    int MAX_TUILES = 24;
    ensemble_tuiles.resize(MAX_TUILES, nullptr);
    int id = 0;

    // Ajout tuile depart
    ensemble_tuiles[id] = new Tuile(id, true);
    tuiles_placees.push_back(id);
    ensemble_tuiles[id]->construire_graphe(g);
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

  void Plateau::etendre_plateau(IdNoeud id) {
    int indice_pioche = piocher();
    tuiles_placees.push_back(indice_pioche);

    Graphe new_g;
    Direction direction_ext;
    int case_entree;
    switch (id.site) {
      case 4:
        direction_ext = GAUCHE;
        case_entree = 11;
        ensemble_tuiles[indice_pioche]->rotation_gauche();
        break;
      case 11:
        direction_ext = DROITE;
        case_entree = 4;
        ensemble_tuiles[indice_pioche]->rotation_droite();
        break;
      case 13:
        direction_ext = BAS;
        case_entree = 2;
        ensemble_tuiles[indice_pioche]->rotation_droite();
        ensemble_tuiles[indice_pioche]->rotation_droite();
        break;
      default:
        direction_ext = HAUT;
        case_entree = 13;
        break;
    }
    ensemble_tuiles[indice_pioche]->construire_graphe(new_g);
    g.fusionner_graphe(new_g);
    Noeud* n_sortie = g.index_noeud(id);
    Noeud* n_entree = g.index_noeud(IdNoeud(indice_pioche, case_entree));
    g.connecter_voisins(n_sortie, n_entree, direction_ext);

    check_objectif(indice_pioche);
  }

  void Plateau::sauver_plateau_dans_dossier(std::string nom_dossier) {
    for (unsigned int i = 0; i < ensemble_tuiles.size(); i++) {
      std::stringstream ss;
      ss << nom_dossier << "tuile_" << i << ".txt";
      ensemble_tuiles[i]->sauver_dans_fichier(ss.str());
    }
  }

  void Plateau::afficher_tuiles() {
    for (unsigned int i = 0; i < ensemble_tuiles.size(); i++) {
      std::cout << "Tuile " << i;
      ensemble_tuiles[i]->afficher();
    }
  }

  void Plateau::afficher_tuiles_placees() {
    for (unsigned int i = 0; i < tuiles_placees.size(); i++) {
      std::cout << "Tuile " << tuiles_placees[i];
      ensemble_tuiles[tuiles_placees[i]]->afficher();
    }
  }

  void Plateau::afficher_graphe() {
    g.afficher();
  }

  /* --------------------------------------------------------- */

  int Plateau::piocher() {
    int pioche;
    pioche_tuiles->retirer(&pioche);
    return pioche;
  }

  void Plateau::check_objectif(int indice_pioche) {
    int site = ensemble_tuiles[indice_pioche]->contient_objectif();
    if (site != -1) {
      Type t = ensemble_tuiles[indice_pioche]->vec_sites[site].type;
      Couleur c = ensemble_tuiles[indice_pioche]->vec_sites[site].couleur;
      std::cout << std::endl;
      switch (c) {
        case JAUNE:
          std::cout << TXT_JAUNE;
          break;
        case VIOLET:
          std::cout << TXT_VIOLET;
          break;
        case VERT:
          std::cout << TXT_VERT;
          break;
        case ORANGE:
          std::cout << TXT_ORANGE;
          break;
        default:
          std::cout << TXT_BOLD;
          break;
      }
      if (t == OBJECTIF) {
        std::cout << "OBJECTIF ";
        objectifs_trouves[indice_couleur(c)] = true;
      } else if (t == SORTIE) {
        std::cout << "SORTIE ";
        sorties_trouvees[indice_couleur(c)] = true;
      }
      std::cout << TXT_CLEAR << "trouvé !" << std::endl;
    }

  }

}
