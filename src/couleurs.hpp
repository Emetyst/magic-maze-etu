#ifndef MMAZE_TERM_COLORS_HPP
#define MMAZE_TERM_COLORS_HPP

namespace MMaze {

  enum Couleur {
    AUCUNE,
    JAUNE,
    VERT,
    ORANGE,
    VIOLET
  };

  int indice_couleur(Couleur c);

  extern const char* TXT_CLEAR;
  extern const char* TXT_BOLD;
  extern const char* TXT_DEFAULT;
  extern const char* TXT_VIOLET;
  extern const char* TXT_ORANGE;
  extern const char* TXT_JAUNE;
  extern const char* TXT_VERT;
  extern const char* BG_DEFAULT;
  extern const char* BG_VIOLET;
  extern const char* BG_ORANGE;
  extern const char* BG_JAUNE;
  extern const char* BG_VERT;

  extern const char* txt_colors[5];
  extern const char* bg_colors[5];

} //end of namespace MMaze

#endif
