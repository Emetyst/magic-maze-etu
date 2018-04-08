#include "tuile.hpp"

#include <cassert>
#include <cstdlib>
#include <ctime>

namespace MMaze {

  Tuile::Tuile(int id, bool depart) {
    id_tuile = id;

    for(unsigned int i = 0; i < 16; i++) {
      vec_sites.push_back(Site(i, AUCUNE, AUCUN));
    }
    vec_murs.resize(24, true);

    if(depart) {
      // Placement points de départ et portes correspondantes
      modifier_site(2, PORTE, ORANGE);
      modifier_site(4, PORTE, VIOLET);
      modifier_site(5, POINT_DEPART, VIOLET);
      modifier_site(6, POINT_DEPART, ORANGE);
      modifier_site(9, POINT_DEPART, JAUNE);
      modifier_site(10, POINT_DEPART, VERT);
      modifier_site(11, PORTE, VERT);
      modifier_site(13, PORTE, JAUNE);
    }
    else {
      // Placement d'un accès
      modifier_site(13, PORTE, AUCUNE);

      // Initialisation de mélangeurs pour décider le nombre, la couleur et la position des portes (au moins une)
      Melangeur position_portes(sizeof(int));
      int a = 2, b = 4, c = 11;
      position_portes.inserer({&a, &b, &c});

      Couleur j = JAUNE, v = VERT, o = ORANGE, vi = VIOLET;
      Melangeur couleur_portes(sizeof(Couleur));
      couleur_portes.inserer({&j, &v, &o, &vi});

      Melangeur nombre_portes(sizeof(int));
      int d = 1, e = 2, f = 3;
      nombre_portes.inserer({&d, &e, &f});
      int nb_portes;
      nombre_portes.retirer(&nb_portes);

      for(int i = 0; i < nb_portes; i++) {
        int n;
        position_portes.retirer(&n);
        Couleur c;
        couleur_portes.retirer(&c);
        modifier_site(n, PORTE, c);
      }
    }

  }

  bool Tuile::mur(Mur m) const {
    return vec_murs[m.index()];
  }

  bool Tuile::accessible(Case c) const {
    /* remplacez ce code */
    return false;
  }

  void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
    assert(i < 5);
    if(i == 0) {
      out << "+---+---+-";
      if (vec_sites[2].type == PORTE) {
        switch (vec_sites[2].couleur) {
          case AUCUNE:
            out << TXT_BOLD << "v";
            break;
          case JAUNE:
            out << TXT_JAUNE << "^";
            break;
          case ORANGE:
            out << TXT_ORANGE << "^";
            break;
          case VERT:
            out << TXT_VERT << "^";
            break;
          case VIOLET:
            out << TXT_VIOLET << "^";
            break;
        }
        out << TXT_CLEAR;
      } 
      else out << "-";
      out << "-+---+";
    } else if(i == 4) {
      out << "+---+-";
      if (vec_sites[13].type == PORTE) {
        switch (vec_sites[13].couleur) {
          case AUCUNE:
            out << TXT_BOLD << "^";
            break;
          case JAUNE:
            out << TXT_JAUNE << "v";
            break;
          case ORANGE:
            out << TXT_ORANGE << "v";
            break;
          case VERT:
            out << TXT_VERT << "v";
            break;
          case VIOLET:
            out << TXT_VIOLET << "v";
            break;
        }
        out << TXT_CLEAR;
      } 
      else out << "-";
      out << "-+---+---+";
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

    if (i == 1) {
      if (vec_sites[4].type == PORTE) {
        switch (vec_sites[4].couleur) {
          case AUCUNE:
            out << TXT_BOLD << ">";
            break;
          case JAUNE:
            out << TXT_JAUNE << "<";
            break;
          case ORANGE:
            out << TXT_ORANGE << "<";
            break;
          case VERT:
            out << TXT_VERT << "<";
            break;
          case VIOLET:
            out << TXT_VIOLET << "<";
            break;
        }
        out << TXT_CLEAR;
      } else out << "|";
    } else out << "|";

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

    if (i == 2) {
      if (vec_sites[11].type == PORTE) {
        switch (vec_sites[11].couleur) {
          case AUCUNE:
            out << TXT_BOLD << "<";
            break;
          case JAUNE:
            out << TXT_JAUNE << ">";
            break;
          case ORANGE:
            out << TXT_ORANGE << ">";
            break;
          case VERT:
            out << TXT_VERT << ">";
            break;
          case VIOLET:
            out << TXT_VIOLET << ">";
            break;
        }
        out << TXT_CLEAR;
      } else out << "|";
    } else out << "|";
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

  void Tuile::sauver_dans_fichier(std::string nom) {
    std::ofstream flux(nom, std::ios::out | std::ios::trunc);
    if(!flux) {
      std::cerr << "Erreur : le fichier " << nom.c_str() << " n'a pas pu être ouvert" << std::endl;
    }
    else {
      flux << "tuile" << std::endl;
      for(unsigned int i = 0; i < vec_murs.size(); i++) {
        if(vec_murs[i]) {
          flux << "mur " << i << std::endl;
        }
      }
      for(unsigned int i = 0; i < vec_sites.size(); i++) {
        if(vec_sites[i].type != AUCUN) {
          flux << "site " << i << " ";

          switch(vec_sites[i].type) {
            case PORTE:
              flux << "porte ";
              break;
            case OBJECTIF:
              flux << "objectif ";
              break;
            case SORTIE:
              flux << "sortie ";
              break;
            case POINT_DEPART:
              flux << "depart ";
              break;
            default:
              break;
          }

          switch(vec_sites[i].couleur) {
            case AUCUNE:
              flux << "aucune ";
              break;
            case JAUNE:
              flux << "jaune ";
              break;
            case VERT:
              flux << "vert ";
              break;
            case ORANGE:
              flux << "orange ";
              break;
            case VIOLET:
              flux << "violet ";
              break;
          }

          flux << std::endl;
        }
      }
      flux << "fin";
      flux.close();
    }
  }

  void Tuile::modifier_site(unsigned int pos, const Type & t, const Couleur & c) {
    vec_sites[pos].type = t;
    vec_sites[pos].couleur = c;
  }

  void Tuile::placer_autre_site(const Type & t, const Couleur & c) {
    Melangeur places_restantes(sizeof(unsigned int));
    for (unsigned int i = 0; i < 16; i++) {
      if (vec_sites[i].type == AUCUN) {
        places_restantes.inserer(&i);
      }
    }
    unsigned int pos;
    places_restantes.retirer(&pos);
    modifier_site(pos, t, c);
  }

  void Tuile::detruire_murs() {

  }

} //end of namespace MMaze