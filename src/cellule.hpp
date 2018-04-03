#ifndef LIFAP6_LISTE_CELLULE_HPP
#define LIFAP6_LISTE_CELLULE_HPP

class Cellule {
  public:
    int valeur;
    Cellule* next;

    Cellule(int val, Cellule* adr = nullptr);
};

#endif
