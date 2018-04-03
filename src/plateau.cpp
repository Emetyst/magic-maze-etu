#include "plateau.hpp"

namespace MMaze {
    Plateau::Plateau() {
		pioche_tuiles = new Melangeur(sizeof(Tuile));

		// Insertion tuile de départ
		Tuile t_depart(TuileBuildOptions(true));
		pioche_tuiles->inserer(&t_depart);
		Tuile t;
		pioche_tuiles->retirer(&t);
		t.save_to_file("../assets/depart.txt");
	}

	Plateau::~Plateau() {
		delete pioche_tuiles;
	}
}