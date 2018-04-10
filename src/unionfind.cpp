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

    UnionFind& UnionFind::operator=(const UnionFind& autre) {
        classe_equiv = autre.classe_equiv;
        return *this;
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
            return true; // Une union a été effectuée
        } else return false; // Les deux noeuds sont dans la même classe donc pas d'union
    }

    bool UnionFind::ont_meme_classe(int n1, int n2) {
        return (find_rep(n1) == find_rep(n2));
    }

    bool UnionFind::ont_meme_classe(const std::vector<int>& n) {
        // assert(n.size() > 0);
        // for (unsigned int i = 0; i < n.size(); i++) {
        //     assert((unsigned int) n[i] < classe_equiv.size());
        // }
        // compression_chemins();
        int representant = find_rep(n[0]);
        for (unsigned int i = 1; i < n.size(); i++) {
            if (representant != find_rep(n[i])) {
                return false;
            }
        }
        return true;
    }

    void UnionFind::compression_chemins() {
        for (unsigned int i = 0; i < classe_equiv.size(); i++) {
            classe_equiv[i].representant = find_rep(i);
        }
    }

    void UnionFind::afficher() {
        std::cout << std::endl;
        compression_chemins();
        std::vector<Liste> classes;
        classes.resize(classe_equiv.size());
        for (unsigned int i = 0; i < classe_equiv.size(); i++) {
            classes[find_rep(i)].ajouter_en_queue(i);
        }
        for (unsigned int i = 0; i < classes.size(); i++) {
            if (classes[i].taille() > 0) {
                std::cout << "classe(" << i << ") : " << classes[i] << std::endl;
            }
        }
    }

}