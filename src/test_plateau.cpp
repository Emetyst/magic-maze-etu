#include "tuile.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"
#include "plateau.hpp"

#include <iostream>
#include <cstdlib>

using namespace MMaze;

int main() {

  Plateau p;
  p.afficher_tuiles_placees();

  p.etendre_plateau(IdNoeud(0, 4));
  p.afficher_tuiles_placees();

  std::cout << std::endl;

//   p.afficher_graphe();
  
//   p.sauver_plateau_dans_dossier("../assets/plateau/");

  return 0;
}
