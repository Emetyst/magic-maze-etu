#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include "tuile.hpp"

namespace MMaze {
  class Plateau {
    public:
      Plateau();
      ~Plateau();

    private:
      Melangeur* pioche_tuiles;
  };
}

#endif