#include "graphe.hpp"

namespace MMaze {
  Graphe::Graphe() {

  }

  Graphe::~Graphe() {
      
  }

  void Graphe::ajouter_noeud(Noeud* noeud) {
    noeuds.push_back(noeud);
  }

  Noeud* Graphe::rechercher_noeud(void* d) {
    for(unsigned int i = 0; i < noeuds.size(); ++i) {
      if(noeuds[i]->donnee == d) {
        return noeuds[i];
      }
    }
    return nullptr;
  }

  void Graphe::supprimer_tete() {
    delete noeuds[0];
  }

  void Graphe::vider() {
    while(!noeuds.empty()) {
      supprimer_tete();
    }
  }
  
  void Graphe::parcourir(Noeud* source, Noeud* destination) {
    // std::priority_queue<int, std::vector<Noeud*>, std::greater<int>> f;
    // std::vector<int> d;
    // std::vector<Noeud*> p;

    // std::map<int, Noeud*> m;
    // // Remplissage du map
    // for(int i = 0; i < noeuds.size(); ++i) {
    //   m.insert(std::pair<int, Noeuds*>(i,noeuds[i]));
    // }

    // d[] = 0;
    // p[] = source;

    // Noeud* n;

    // for(int i = 0; i < noeuds.size(); ++i) {
    //   if(noeuds[i] != source) {
    //     d[] = std::numeric_limits<int>::max();
    //     p[] = nullptr;
    //   }
    // }

    // while(!f.empty()) {
    //   n = f.top();
    //   f.pop();
    //   for(int i = 0; i < n->aretes.size(); ++i) {
    //     int dist = d[] + LE COUT;
    //     if(dist < d[]) {
    //       if(d[] == std::numeric_limits<int>::max()) {
    //         f.insert();
    //       }
    //     }
    //   }
    // }
  }
}
