#include "tuile.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"
#include "plateau.hpp"

#include <iostream>
#include <cstdlib>

using namespace MMaze;

int main() {

  Tuile t, t_depart(0, true);
  t.placer_autre_site(SORTIE, VERT);
  t.placer_autre_site(OBJECTIF, VIOLET);
  std::cout << std::endl << "Tuile de départ" << std::endl << t_depart << std::endl;
  std::cout << std::endl << "Tuile classique" << std::endl << t << std::endl;

  t.rotation_droite();
  std::cout << std::endl << "Tuile classique (après rotation droite)" << std::endl << t << std::endl;
  t.rotation_gauche();
  std::cout << std::endl << "Tuile classique (après rotation gauche)" << std::endl << t << std::endl;
    

  // utilisation des couleurs
  std::cout
    << TXT_JAUNE << "&"
    << TXT_ORANGE << "&"
    << TXT_VERT << "&"
    << TXT_VIOLET << "&"
    << TXT_CLEAR
    << BG_JAUNE << "&"
    << BG_ORANGE << "&"
    << BG_VERT << "&"
    << BG_VIOLET << "&"
    << TXT_CLEAR
    << std::endl;
  
  t.sauver_dans_fichier("../assets/tuile_classique.txt");
  t_depart.sauver_dans_fichier("../assets/tuile_depart.txt");

  Plateau p;
  p.afficher_tuiles();
  p.sauver_plateau_dans_dossier("../assets/plateau/");

  // Tuile t_fichier;
  // t_fichier.lire_dans_fichier("../assets/MMaze_tests/tuile_0.txt");
  // std::cout << std::endl << std::endl << "Tuile t_fichier" << std::endl << t_fichier << std::endl;

  return 0;
}
