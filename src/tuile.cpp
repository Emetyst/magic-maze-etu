#include "tuile.hpp"

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace MMaze {

  Tuile::Tuile(bool depart) {
    srand(time(NULL));

    /***** Initialisation du mélangeur de couleurs *****/
    Couleur j = JAUNE, v = VERT, o = ORANGE, vi = VIOLET, a = AUCUNE;
    couleurs_portes = new Melangeur(sizeof(Couleur));
    couleurs_portes->inserer({&j, &v, &o, &vi});

    if (depart) {
      // Tuile de depart

      for (unsigned int i = 0; i < 16; i++) {
        // Si on veut une porte
        if ((i == 2) || (i == 4) || (i == 11) || (i == 13)) {
          Couleur* c = nullptr;
          couleurs_portes->retirer(c);
          tab_sites.push_back(Site(i, (*c), PORTE));
        }

        // Si on veut une case de depart
        else if ((i == 5) || (i == 6) || (i == 9) || (i == 10)) {
          tab_sites.push_back(Site(i, AUCUNE, POINT_DEPART));
        }

        else tab_sites.push_back(Site(i, AUCUNE));
      }
    }

    else {
      // Tuile classique
      couleurs_portes->inserer(&a);
      int nb_portes = 0;

      Melangeur* pos_portes = new Melangeur(sizeof(unsigned int));
      unsigned int a = 2, b = 4, c = 11, d = 13;
      pos_portes->inserer({&a, &b, &c, &d});
      std::vector<unsigned int> positions;

      while (nb_portes <= 4) {
        if (nb_portes < 2 || rand() % 2 == 1) {
          nb_portes++;
          unsigned int * n = nullptr;
          pos_portes->retirer(n);
          positions.push_back(*n);
        }
      }

      for (unsigned int i = 0; i < 16; i++) {
        // if ()

        if ((i == 2) || (i == 4) || (i == 11) || (i == 13)) {
          // Porte
          if (rand() % 2 == 1) {
            // pile
            Couleur* c = nullptr;
            couleurs_portes->retirer(c);
            tab_sites.push_back(Site(i, (*c), PORTE));
            nb_portes++;
          }
          else {
            if ((nb_portes < 2) && ((i == 11) || (i == 13))) {}
            // face

          }
        }
      }
    }
  }

  bool Tuile::mur(Mur m) const {
    /* remplacez ce code */
    return rand() % 2;
  }

  bool Tuile::accessible(Case c) const {
    /* remplacez ce code */
    return false;
  }

  void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
    assert(i < 5);
    if(i == 0 || i == 4) {
      out << "+---+---+---+---+";
    } else {
      out << "+";
      for(unsigned int m = 0; m < 4; ++m) {
        Case up = Case(i-1, m);
        Case down = Case(i, m);
        if(mur(Mur(up, down))) {
          out << "---+";
        } else {
          out << "   +";
        }
      }
    }
  }

  void Tuile::afficher_vertical(std::ostream& out, unsigned int i) const {
    assert(i < 4);
    out << "|";
    for(unsigned int m = 0; m < 4; ++m) {
      out << "   ";
      if(m < 3) {
        Case left = Case(i, m);
        Case right = Case(i, m+1);
        if(m < 3 && mur(Mur(left, right))) {
          out << "|";
        } else {
          out << " ";
        }
      }
    }
    out << "|";
  }

  std::ostream& operator<< (std::ostream& out, const Tuile& t) {
    for(unsigned int i = 0; i < 4; ++i) {
      t.afficher_horizontal(out, i);
      out << std::endl;
      t.afficher_vertical(out, i);
      out << std::endl;
    }
    t.afficher_horizontal(out, 4);
    return out;
  }

} //end of namespace MMaze
