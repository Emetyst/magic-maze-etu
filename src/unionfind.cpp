#include "unionfind.hpp"

namespace MMaze {

    ClasseEquiv::ClasseEquiv(int rep) {
        representant = rep;
        hauteur = 1;
    }

    ClasseEquiv::~ClasseEquiv() {

    }
    
    UnionFind::UnionFind(int nb_classes) {
        for (int i = 0; i < nb_classes; i++) {
            classe_equiv.push_back(ClasseEquiv(i));
        }
    }

    UnionFind::~UnionFind() {
        classe_equiv.clear();
    }

    int UnionFind::find_rep(int n) {
        if (classe_equiv[n].representant != n) {
            classe_equiv[n].representant = find_rep(classe_equiv[n].representant);
        }
        return classe_equiv[n].representant;
    }

    bool UnionFind::union_classes(int n1, int n2) {
        int rep_n1 = find_rep(n1);
        int rep_n2 = find_rep(n2);
        if (rep_n1 != rep_n2) {
            if (classe_equiv[rep_n1].hauteur < classe_equiv[rep_n2].hauteur) {
                classe_equiv[rep_n1].representant = rep_n2;
            } else {
                classe_equiv[rep_n2].representant = rep_n1;
                if (classe_equiv[rep_n1].hauteur == classe_equiv[rep_n2].hauteur) {
                    classe_equiv[rep_n1].hauteur++;
                }
            }
            return true;
        } else return false;
    }

}