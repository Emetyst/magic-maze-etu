#include "couleurs.hpp"

namespace MMaze {

  int indice_couleur(Couleur c) {
    int res;
    switch (c) {
      case VIOLET:
        res = 0;
        break;
      case ORANGE:
        res = 1;
        break;
      case JAUNE:
        res = 2;
        break;
      case VERT:
        res = 3;
        break;
      default:
        res = -1;
        break;
    }
    return res;
  }

  const char* TXT_CLEAR = "\x1B[0m";
  const char* TXT_BOLD = "\x1B[1m";
  const char* TXT_DEFAULT = "\x1B[39m";
  const char* TXT_VIOLET = "\x1B[38;5;135m";
  const char* TXT_ORANGE = "\x1B[38;5;208m";
  const char* TXT_JAUNE = "\x1B[38;5;11m";
  const char* TXT_VERT = "\x1B[38;5;10m";
  const char* BG_DEFAULT = "\x1B[49m";
  const char* BG_VIOLET = "\x1B[48;5;135m";
  const char* BG_ORANGE = "\x1B[48;5;208m";
  const char* BG_JAUNE = "\x1B[48;5;11m";
  const char* BG_VERT = "\x1B[48;5;10m";

  const char* txt_colors[5] = {TXT_DEFAULT, TXT_JAUNE, TXT_VERT, TXT_ORANGE, TXT_VIOLET};
  const char* bg_colors[5] = {BG_DEFAULT, BG_JAUNE, BG_VERT, BG_ORANGE, BG_VIOLET};

} //end of namespace MMaze

