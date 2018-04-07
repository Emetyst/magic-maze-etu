#include "tuile.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"
#include "plateau.hpp"

#include <iostream>
#include <cstdlib>

using namespace MMaze;

int main() {

  Tuile t, t_depart(true);
  std::cout << std::endl << "Tuile de départ" << std::endl << t_depart << std::endl;
  std::cout << std::endl << "Tuile classique" << std::endl << t << std::endl;

  //utilisation des couleurs
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
  
  t.sauver_dans_fichier("../assets/test_ecriture_tuile.txt");
  t_depart.sauver_dans_fichier("../assets/tuile_depart.txt");

  // Plateau p;

  return 0;
}
