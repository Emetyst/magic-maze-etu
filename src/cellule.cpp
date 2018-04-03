#include "cellule.hpp"

Cellule::Cellule (int val, Cellule* adr) {
  valeur = val;
  next = adr;
}
