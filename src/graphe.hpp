#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include "noeud.hpp"
#include "arete.hpp"

namespace MMaze {

  class Graphe {
    public:
      Graphe();
      ~Graphe();
      

      bool sont_voisins(Noeud* x, Noeud* y);
      std::vector<Arete> voisins(Noeud* x);
      void ajouter_noeud(Noeud* x);
      // void supprimer_noeud(Noeud* x);
      void ajouter_arete(Noeud* src, Noeud* dest, Direction dir);
      // void supprimer_arete(Noeud* x, Noeud* y);
      IdNoeud index_noeud(Noeud* noeud);
      Noeud* index_noeud(const IdNoeud& id);
      unsigned int nb_noeuds();
      unsigned int nb_aretes();

      void connecter_voisins(Noeud* src, Noeud* dest, Direction dir);
      void fusionner_graphe(Graphe& autre);

      void afficher();

    private:
      std::vector<Noeud*> noeuds;
      unsigned int compteur_aretes;
  };
}

#endif
