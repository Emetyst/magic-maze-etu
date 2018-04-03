#include "tuile.hpp"

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace MMaze {

	SiteBuildOptions::SiteBuildOptions(unsigned int p, Type t, Couleur c) {
		pos = p;
		type = t;
		couleur = c;
	}

	TuileBuildOptions::TuileBuildOptions(bool depart) {
		if (depart) {
			// Placement points de départ et 4 portes correspondantes
			sites.push_back(SiteBuildOptions(2, PORTE, ORANGE));
			sites.push_back(SiteBuildOptions(4, PORTE, VIOLET));
			sites.push_back(SiteBuildOptions(5, POINT_DEPART, VIOLET));
			sites.push_back(SiteBuildOptions(6, POINT_DEPART, ORANGE));
			sites.push_back(SiteBuildOptions(9, POINT_DEPART, JAUNE));
			sites.push_back(SiteBuildOptions(10, POINT_DEPART, VERT));
			sites.push_back(SiteBuildOptions(11, PORTE, VERT));
			sites.push_back(SiteBuildOptions(13, PORTE, JAUNE));
		}
		else {
			// Placement d'un accès
			sites.push_back(SiteBuildOptions(13, PORTE, AUCUNE));

			// Initialisation de mélangeurs pour décider aléatoirement le nombre, la couleur et la position des portes (au moins une)
			Melangeur pos_portes(sizeof(int));
			int a = 2, b = 4, c = 11;
			pos_portes.inserer({&a, &b, &c});
			
			Couleur j = JAUNE, v = VERT, o = ORANGE, vi = VIOLET;
			Melangeur couleurs_portes(sizeof(Couleur));
			couleurs_portes.inserer({&j, &v, &o, &vi});

			Melangeur nombre_portes(sizeof(int));
			int d = 1, e = 2, f = 3;
			nombre_portes.inserer({&d, &e, &f});
			int nb_portes;
			nombre_portes.retirer(&nb_portes);

			for (int i = 0; i < nb_portes; i++) {
				int n;
				pos_portes.retirer(&n);
				Couleur c;
				couleurs_portes.retirer(&c);
				sites.push_back(SiteBuildOptions(n, PORTE, c));
			}
		}
	}


	// -----------------------------------

	Tuile::Tuile(TuileBuildOptions options) {
		for (unsigned int i = 0; i < 16; i++) {
			tab_sites.push_back(Site(i, AUCUNE, AUCUN));
		}
		tab_murs.resize(24, true);
		for (unsigned int i = 0; i < options.sites.size(); i++) {
			tab_sites[options.sites[i].pos].type = options.sites[i].type;
			tab_sites[options.sites[i].pos].couleur = options.sites[i].couleur;
		}

		detruire_murs(options);
	}

	Tuile::~Tuile() {
		
	}

	bool Tuile::mur(Mur m) const {
		return tab_murs[m.index()];
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

	void Tuile::save_to_file(std::string filename) {
		std::ofstream flux(filename, std::ios::out | std::ios::trunc);
		if (!flux) {
			std::cerr << "Erreur : le fichier " << filename.c_str() << " n'a pas pu être ouvert" << std::endl;
		}
		else {
			flux << "tuile" << std::endl;
			for (unsigned int i = 0; i < tab_murs.size(); i++) {
				if (tab_murs[i]) {
					flux << "mur " << i << std::endl;
				}
			}
			for (unsigned int i = 0; i < tab_sites.size(); i++) {
				if (tab_sites[i].type != AUCUN) {
					flux << "site " << i << " ";
					switch (tab_sites[i].type) {
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
					switch (tab_sites[i].couleur) {
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

	void Tuile::detruire_murs(TuileBuildOptions options) {
		
	}

} //end of namespace MMaze



/* 
		srand(time(NULL));

		//  Initialisation du mélangeur de couleurs
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
*/