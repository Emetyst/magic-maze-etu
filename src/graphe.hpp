#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include "noeud.hpp"

namespace MMaze {

  class Graphe {
    public:
      Graphe();
      ~Graphe();

      bool sont_voisins(int x, int y);
      std::vector<Noeud*> voisins(Noeud* x);
      void ajouter_sommet(Noeud* x);
      void supprimer_sommet(Noeud* x);
      void ajouter_arete(Noeud* x, Noeud* y);
      void supprimer_arete(Noeud* x, Noeud* y);



    private:
      std::vector<std::vector<Noeud*>> noeuds;
  };
}

#endif
