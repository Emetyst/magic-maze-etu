#include "arete.hpp"

Arete::Arete(Noeud* n1, Noeud* n2) {
    source = n1;
    destination = n2;
}

Arete::~Arete() {
    delete source;
    delete destination;
}
