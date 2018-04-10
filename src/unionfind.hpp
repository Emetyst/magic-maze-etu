#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include "liste.hpp"

#include <vector>

namespace MMaze {

    class ClasseEquiv {
        public:
            ClasseEquiv(int rep);
            ~ClasseEquiv();
        
            int representant;
            int hauteur;
    };
    
    class UnionFind {
        public:
            UnionFind(int nb_classes);
            ~UnionFind();

            int find_rep(int n);
            bool union_classes(int n1, int n2);

            std::vector<ClasseEquiv> classe_equiv;
    };

}

#endif