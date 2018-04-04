#include "site.hpp"

namespace MMaze {
  Site::Site(unsigned int li, unsigned int col, Couleur c, Type t) : Case(li, col) {
    type = t;
    couleur = c;
  }

  Site::Site(unsigned int index, Couleur c, Type t) : Case(index) {
    type = t;
    couleur = c;
  }
}