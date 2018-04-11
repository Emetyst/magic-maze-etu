#include "skip-list.hpp"

namespace MMaze {
	SkipList::SkipList() {
		// srand(time(NULL));
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		generator = std::default_random_engine (seed);

		size = 0;
		rubbish.push_back(nullptr);
	}

	SkipList::SkipList(const SkipList& l) {
		// srand(time(NULL));
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		generator = std::default_random_engine (seed);

		size = 0;
		rubbish.push_back(nullptr);
		Cell* c_tmp = l.rubbish[0];
		while (c_tmp != nullptr) {
			add(c_tmp->priorite);
			c_tmp = c_tmp->v_next[0];
		}
	}

	SkipList::SkipList(const std::vector<int> & v_elt) {
		// srand(time(NULL));
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		generator = std::default_random_engine (seed);

		size = 0;
		rubbish.push_back(nullptr);
		add(v_elt);
	}

	SkipList& SkipList::operator=(const SkipList& l) {
		clear();
		
		Cell* c_tmp = l.rubbish[0];
		while (c_tmp != nullptr) {
			add(c_tmp->priorite);
			c_tmp = c_tmp->v_next[0];
		}

		return *this;
	}

	SkipList::~SkipList() {
		Cell* c_tmp = rubbish[0];
		while (c_tmp != nullptr) {
			Cell* c_tmp_next = c_tmp->v_next[0];
			delete c_tmp;
			c_tmp = c_tmp_next;
		}
	}

	void SkipList::add(int elt, Noeud* n) {
		Cell* c_tmp = new Cell(elt, n);
		
		std::uniform_int_distribution<int> distribution(0, 1);
		while (distribution(generator)) c_tmp->v_next.push_back(nullptr);
		
		std::vector<Cell*>* current_vector = &rubbish;
		int current_level = ((max_levels() < c_tmp->v_next.size()) ? max_levels() : c_tmp->v_next.size()) - 1;

		while (current_level >= 0) {
			Cell* current_cell = (*current_vector)[current_level];
			if (current_cell == nullptr) {
				(*current_vector)[current_level] = c_tmp;
				current_level--;
			}
			else if (current_cell->priorite < elt) {
				current_vector = &(current_cell->v_next);
			}
			else /*if (current_cell->priorite > elt)*/ {
				c_tmp->v_next[current_level] = current_cell;
				(*current_vector)[current_level] = c_tmp;
				current_level--;
			}
		}

		for (unsigned int i = rubbish.size(); i < c_tmp->v_next.size(); i++) rubbish.push_back(c_tmp);

		size++;
	}

	void SkipList::add(const std::vector<int> & v_elt) {
		for (unsigned int i = 0; i < v_elt.size(); i++) {
			add(v_elt[i]);
		}
	}

	bool SkipList::find(int elt) {
		std::vector<Cell*>* current_vector = &rubbish;
		int current_level = max_levels() - 1;

		while (current_level >= 0) {
			Cell* current_cell = (*current_vector)[current_level];
			if (current_cell == nullptr) current_level--;
			else if (current_cell->priorite == elt) return true;
			else if (current_cell->priorite < elt) current_vector = &(current_cell->v_next);
			else /*if (current_cell->priorite > elt)*/ current_level--;
		}
		return false;
	}

	bool SkipList::find(const std::vector<int> & v_elt) {
		for (unsigned int i = 0; i < v_elt.size(); i++) {
			if (!find(v_elt[i])) return false;
		}
		return true;
	}

	void SkipList::remove(int elt) {
		std::vector<Cell*>* current_vector = &rubbish;
		int current_level = max_levels() - 1;
		Cell* to_remove = nullptr;

		while (current_level >= 0) {
			Cell* current_cell = (*current_vector)[current_level];
			if (current_cell == nullptr) current_level--;
			else if (current_cell->priorite == elt) {
				if (to_remove == nullptr) to_remove = current_cell;
				(*current_vector)[current_level] = current_cell->v_next[current_level];
				current_level--;
			}
			else if (current_cell->priorite < elt) current_vector = &(current_cell->v_next);
			else /*if (current_cell->priorite > elt)*/ current_level--;
		}

		if (to_remove != nullptr) {
			delete to_remove;
			size--;
		}
	}

	void SkipList::remove(Noeud* n) {
		Cell* to_remove = rubbish[0];
		while (to_remove != nullptr) {
			if (to_remove->noeud == n) break;
			to_remove = to_remove->v_next[0];
		}
		if (to_remove == nullptr) return;

		std::vector<Cell*>* current_vector = &rubbish;
		int current_level = max_levels() - 1;

		while (current_level >= 0) {
			Cell* current_cell = (*current_vector)[current_level];
			if (current_cell == nullptr) current_level--;
			else if (current_cell->noeud == to_remove) {
				(*current_vector)[current_level] = current_cell->v_next[current_level];
				current_level--;
			}
			else if (current_cell->priorite < elt) current_vector = &(current_cell->v_next);
			else /*if (current_cell->priorite > elt)*/ current_level--;
		}

		if (to_remove != nullptr) {
			delete to_remove;
			size--;
		}
	}

	void SkipList::remove(const std::vector<int> & v_elt) {
		for (unsigned int i = 0; i < v_elt.size(); i++) {
			remove(v_elt[i]);
		}
	}

	void SkipList::remove_head() {
		Cell* c_tmp = rubbish[0];
		for (unsigned int i = 0; i < c_tmp->v_next.size(); i++) {
			rubbish[i] = c_tmp->v_next[i];
		}
		delete c_tmp;
	}

	void SkipList::clear() {
		Cell* c_tmp = rubbish[0];
		while (c_tmp != nullptr) {
			Cell* c_tmp_next = c_tmp->v_next[0];
			delete c_tmp;
			c_tmp = c_tmp_next;
		}
		while (rubbish.size() > 1) {
			rubbish.pop_back();
		}
		rubbish[0] = nullptr;
		size = 0;
	}

	unsigned int SkipList::max_levels() const {
		return rubbish.size();
	}

	int SkipList::length() const {
		return size;
	}

	void SkipList::show() const {
		std::cout << "x" << "	";
		for (unsigned int i = 0; i < rubbish.size(); i++) std::cout << ((rubbish[i] == nullptr) ? "x" : "|") << "	";
		std::cout << std::endl;

		Cell* c_tmp = rubbish[0];
		while (c_tmp != nullptr) {
			std::cout << c_tmp->priorite << "	";
			for (unsigned int i = 0; i < c_tmp->v_next.size(); i++) {
				std::cout << ((c_tmp->v_next[i] == nullptr) ? "x" : "|") << "	";
			}
			std::cout << std::endl;
			c_tmp = c_tmp->v_next[0];
		}
		std::cout << std::endl;
	}

	void SkipList::show_details() const {
		for (int i = max_levels() - 1; i >= 0; i--) {
			std::cout << "L" << i << "	";
			std::cout << ((rubbish[i] == nullptr) ? "--x" : "---->") << "	";
			Cell* c_tmp = rubbish[0];
			while (c_tmp != nullptr) {
				if ((int) (c_tmp->v_next.size() - 1) >= i) {
					std::cout << ((c_tmp->v_next[i] == nullptr) ? "--x" : "---->");
				}
				std::cout << "	";
				c_tmp = c_tmp->v_next[0];
			}
			std::cout << std::endl;
		}
		std::cout << "	" << "X" << "	";
		Cell* c_tmp = rubbish[0];
		while (c_tmp != nullptr) {
			std::cout << c_tmp->priorite << "	";
			c_tmp = c_tmp->v_next[0];
		}
		std::cout << "Length : " << length() << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const SkipList& l) {
		out << "[ ";
		Cell* c_tmp = l.rubbish[0];
		while (c_tmp != nullptr) {
			out << c_tmp->priorite << " ";
			c_tmp = c_tmp->v_next[0];
		}
		out << "]";
		return out;
	}
}