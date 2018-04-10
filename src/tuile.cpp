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

    detruire_murs();
    construire_graphe();
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
      int k = (4 * i) + m;
      out << " ";
      switch (vec_sites[k].couleur) {
        case AUCUNE:
          out << TXT_DEFAULT;
          break;
        case JAUNE:
          out << TXT_JAUNE;
          break;
        case ORANGE:
          out << TXT_ORANGE;
          break;
        case VERT:
          out << TXT_VERT;
          break;
        case VIOLET:
          out << TXT_VIOLET;
          break;
      }
      if (vec_sites[k].type == OBJECTIF) out << "O";
      else if (vec_sites[k].type == SORTIE) out << "S";
      else if (vec_sites[k].type == POINT_DEPART) out << "D";
      else out << TXT_CLEAR << " ";
      out << TXT_CLEAR << " ";      
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

  void Tuile::afficher() {
    std::cout << std::endl;
    for(unsigned int i = 0; i < 4; ++i) {
      afficher_horizontal(std::cout, i);
      std::cout << std::endl;
      afficher_vertical(std::cout, i);
      std::cout << std::endl;
    }
    afficher_horizontal(std::cout, 4);
    std::cout << std::endl;
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

  void Tuile::lire_dans_fichier(std::string nom) {
    std::ifstream flux(nom, std::ios::in);
    if(!flux) {
      std::cerr << "Erreur : le fichier " << nom.c_str() << " n'a pas pu être ouvert" << std::endl;
    }
    else {
      reset_tuile();
      std::string tuile;
      flux >> tuile;
      std::string element;
      flux >> element;
      while (element != "fin") {
        if (element == "mur") {
          int pos_mur;
          flux >> pos_mur;
          vec_murs[pos_mur] = true;
        }
        else if (element == "site") {
          int pos_site;
          std::string type_site;
          std::string couleur_site;
          flux >> pos_site >> type_site >> couleur_site;

          Type t = AUCUN;
          if (type_site == "porte") t = PORTE;
          if (type_site == "depart") t = POINT_DEPART;
          if (type_site == "objectif") t = OBJECTIF;
          if (type_site == "sortie") t = SORTIE;

          Couleur c = AUCUNE;
          if (couleur_site == "orange") c = ORANGE;
          if (couleur_site == "violet") c = VIOLET;
          if (couleur_site == "jaune") c = JAUNE;
          if (couleur_site == "vert") c = VERT;
          if (couleur_site == "aucune") c = AUCUNE;

          modifier_site(pos_site, t, c);
        }
        flux >> element;
      }
      flux.close();
    }

  }

  void Tuile::reset_tuile() {
    for (unsigned int i = 0; i < vec_sites.size(); i++) {
      modifier_site(i, AUCUN, AUCUNE);
    }
    for (unsigned int i = 0; i < vec_murs.size(); i++) {
      vec_murs[i] = false;
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
    detruire_murs();
  }

  void Tuile::detruire_murs() {
    UnionFind uf(16);
    std::vector<int> sites;
    for (unsigned int i = 0; i < vec_sites.size(); i++) {
      if (vec_sites[i].type != AUCUN) {
        sites.push_back(i);
      }
    }
    relier_sites(uf, sites);
    // eliminer_impasses(uf, sites);
  }

  void Tuile::relier_sites(UnionFind& uf, std::vector<int> sites) {
    Melangeur murs_a_detruire(sizeof(int));
    for (unsigned int i = 0; i < vec_murs.size(); i++) {
      vec_murs[i] = true;
      murs_a_detruire.inserer(&i);
    }
    while (!uf.ont_meme_classe(sites)) {
      int indice_mur;
      murs_a_detruire.retirer(&indice_mur);
      Mur m(indice_mur);

      int rep_c0 = uf.find_rep(m[0].index()); // représentant de la case d'un côté du mur
      int rep_c1 = uf.find_rep(m[1].index()); // représentant de la case de l'autre côté du mur
      if (rep_c0 != rep_c1) {
        uf.union_classes(rep_c0, rep_c1);
        vec_murs[indice_mur] = false;
      }
    }
  }

  void Tuile::eliminer_impasses(UnionFind& uf, std::vector<int> sites) {
    std::vector<int> impasses = reste_impasses();
    while (impasses.size() != 0) {
      for (unsigned int i = 0; i < impasses.size(); i++) {
        if ( (i < 4) ? false : !mur(Mur(vec_sites[i], vec_sites[i].haut())) ) {
          vec_murs[Mur(vec_sites[i], vec_sites[i].haut()).index()] = true;
        }
        if ( (i > 11) ? true : mur(Mur(vec_sites[i], vec_sites[i].bas())) ) {
          vec_murs[Mur(vec_sites[i], vec_sites[i].bas()).index()] = true;
        }
        if ( (i%4 == 0) ? true : mur(Mur(vec_sites[i], vec_sites[i].gauche())) ) {
          vec_murs[Mur(vec_sites[i], vec_sites[i].gauche()).index()] = true;
        }
        if ( (i%4 == 3) ? true : mur(Mur(vec_sites[i], vec_sites[i].droite())) ) {
          vec_murs[Mur(vec_sites[i], vec_sites[i].droite()).index()] = true;
        }
      }
      impasses = reste_impasses();
    }
    
  }

  std::vector<int> Tuile::reste_impasses() {
    std::vector<int> impasses;
    for (unsigned int i = 0; i < vec_sites.size(); i++) {
      if (vec_sites[i].type == AUCUN) {
        std::vector<bool> murs;
        murs.push_back( (i < 4) ? true : mur(Mur(vec_sites[i], vec_sites[i].haut())) );
        murs.push_back( (i > 11) ? true : mur(Mur(vec_sites[i], vec_sites[i].bas())) );
        murs.push_back( (i%4 == 0) ? true : mur(Mur(vec_sites[i], vec_sites[i].gauche())) );
        murs.push_back( (i%4 == 3) ? true : mur(Mur(vec_sites[i], vec_sites[i].droite())) );
        int nb_murs_up = 0;
        for (unsigned int i = 0; i < murs.size(); i++) {
          if (murs[i]) nb_murs_up++;
        }
        if (nb_murs_up == 3) impasses.push_back(i);
      }
    }
    return impasses;
  }

  void Tuile::construire_graphe() {
    
  }

  void Tuile::rotation_gauche() {
    std::vector<Site> temp_sites;
    std::vector<bool> temp_murs;
    for(unsigned int i = 0; i < 16; i++) {
      temp_sites.push_back(Site(i, AUCUNE, AUCUN));
    }
    temp_murs.resize(vec_murs.size(), false);

    for (unsigned int i = 0; i < vec_sites.size(); i++) {
      int tmp_index = (vec_sites[i].tourne(-1)).index();
      temp_sites[i].type = vec_sites[tmp_index].type;
      temp_sites[i].couleur = vec_sites[tmp_index].couleur;
    }
    vec_sites = temp_sites;

    for (unsigned int i = 0; i < vec_murs.size(); i++) {
      int tmp_index = (Mur(i).tourne(-1)).index();
      temp_murs[i] = vec_murs[tmp_index];
    }
    vec_murs = temp_murs;

    construire_graphe();
  }

  void Tuile::rotation_droite() {
    std::vector<Site> temp_sites;
    std::vector<bool> temp_murs;
    for(unsigned int i = 0; i < 16; i++) {
      temp_sites.push_back(Site(i, AUCUNE, AUCUN));
    }
    temp_murs.resize(vec_murs.size(), false);

    for (unsigned int i = 0; i < vec_sites.size(); i++) {
      int tmp_index = (vec_sites[i].tourne(1)).index();
      temp_sites[i].type = vec_sites[tmp_index].type;
      temp_sites[i].couleur = vec_sites[tmp_index].couleur;
    }
    vec_sites = temp_sites;

    for (unsigned int i = 0; i < vec_murs.size(); i++) {
      int tmp_index = (Mur(i).tourne(1)).index();
      temp_murs[i] = vec_murs[tmp_index];
    }
    vec_murs = temp_murs;

    construire_graphe();
  }

} //end of namespace MMaze