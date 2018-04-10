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
            void union_classes(int n1, int n2);
            bool ont_meme_classe(const std::vector<int>& n);
            void compression_chemins();

        private:
            std::vector<ClasseEquiv> classe_equiv;
    };

}

#endif