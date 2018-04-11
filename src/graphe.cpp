#include "graphe.hpp"

namespace MMaze {
  Graphe::Graphe() {
    compteur_aretes = 0;
  }

  Graphe::~Graphe() {
    for (unsigned int i = 0; i < noeuds.size(); i++) {
      delete noeuds[i];
    }
    noeuds.clear();
  }

  bool Graphe::sont_voisins(Noeud* x, Noeud* y) {
    return x->est_voisin(y) /* && y->est_voisin(x) */;
  }

  std::vector<Arete> Graphe::voisins(Noeud* x) {
    return x->voisins;
  }

  void Graphe::ajouter_noeud(Noeud* noeud) {
    noeuds.push_back(noeud);
  }

  void Graphe::ajouter_arete(Noeud* src, Noeud* dest, Direction dir) {
    if (src != dest) {
      if (!sont_voisins(src, dest)) {
        src->ajouter_voisin(dir, dest);
        dest->ajouter_voisin(opposee(dir), src);
        compteur_aretes++;
      }
    }
  }

  IdNoeud Graphe::index_noeud(Noeud* noeud) {
    return noeud->id;
  }

  Noeud* Graphe::index_noeud(const IdNoeud& id) {
    for (unsigned int i = 0; i < noeuds.size(); i++) {
      if (noeuds[i]->compare_id(id)) return noeuds[i];
    }
    return nullptr;
  }

  unsigned int Graphe::nb_noeuds() {
    return noeuds.size();
  }

  unsigned int Graphe::nb_aretes() {
    return compteur_aretes;
  }

  void Graphe::connecter_voisins(Noeud* src, Noeud* dest, Direction dir) {
    std::vector<Arete> new_v_dest = src->voisins_direction(opposee(dir));
    new_v_dest.push_back(Arete(opposee(dir), src));
    std::vector<Arete> new_v_src = dest->voisins_direction(dir);
    new_v_src.push_back(Arete(dir, dest));
    for (unsigned int i = 0; i < new_v_dest.size(); i++) {
      for (unsigned int j = 0; j < new_v_src.size(); j++) {
        ajouter_arete(new_v_dest[i].destination, new_v_src[j].destination, dir);
      }
    }
  }

  void Graphe::fusionner_graphe(Graphe& autre) {
    for (unsigned int i = 0; i < autre.noeuds.size(); i++) {
      noeuds.push_back(autre.noeuds[i]);
    }
    autre.noeuds.clear();
  }

  void Graphe::afficher() {
    for (unsigned int i = 0; i < noeuds.size(); i++) {
      for (unsigned int j = 0; j < noeuds[i]->voisins.size(); j++) {
        std::cout << noeuds[i]->id.site << " --";
        switch (noeuds[i]->voisins[j].direction) {
          case HAUT:
            std::cout << "h";
            break;
          case BAS:
            std::cout << "b";
            break;
          case GAUCHE:
            std::cout << "g";
            break;
          case DROITE:
            std::cout << "d";
            break;
        }
        std::cout << "--> " << noeuds[i]->voisins[j].destination->id.site << std::endl;
      }
    }
  }

}
