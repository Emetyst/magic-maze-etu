#include "plateau.hpp"

namespace MMaze {
  Plateau::Plateau() {
    pioche_tuiles = new Melangeur(sizeof(pioche_tuiles));

    // Insertion tuile de départ
    Tuile t_depart(TuileOptions(true));
    pioche_tuiles->inserer(&t_depart);
    Tuile t;
    // pioche_tuiles->retirer(&t); // il n'aime pas ça !!
    t.sauver_dans_fichier("../assets/depart.txt");
  }

  Plateau::~Plateau() {
    delete pioche_tuiles;
  }
}