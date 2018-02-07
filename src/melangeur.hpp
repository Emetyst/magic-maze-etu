#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP

namespace MMaze {

  class Melangeur {

    public:
      Melangeur(int octets);
      ~Melangeur();
      void inserer(const void* elem);
      void retirer(void* elem);
      void vider();
      int taille();

    /* vos membres ici */

  };

} //end of namespace MMaze

#endif
