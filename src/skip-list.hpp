#ifndef SKIP_LIST_HPP
#define SKIP_LIST_HPP

#include "cell.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>

namespace MMaze {
	class SkipList {
		public:
			/* Constructeurs */
			SkipList();
			SkipList(const SkipList& l);
			SkipList(const std::vector<int> & v_elt);

			/* Affectation */
			SkipList& operator=(const SkipList& l);

			/* Destructeur */
			~SkipList();

			/* Insertion d'éléments */
			void add(int elt, Noeud* n = nullptr);
			void add(const std::vector<int> & v_elt);

			/* Recherche d'élément */
			bool find(int elt);
			bool find(const std::vector<int> & v_elt);

			/* Suppression d'éléments */
			void remove(int elt);
			void remove(Noeud* n);
			void remove(const std::vector<int> & v_elt);
			void remove_head();
			void clear();

			/* Consultation valeurs attributs */
			unsigned int max_levels() const;
			int length() const;

			/* Affichage */
			void show() const;
			void show_details() const;
			friend std::ostream& operator<<(std::ostream& out, const SkipList& l);

		private:
			std::vector<Cell*> rubbish;
			int size;
			unsigned seed;
			std::default_random_engine generator;
	};
}
#endif
