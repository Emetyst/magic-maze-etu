#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP

#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>

namespace MMaze {

  class Melangeur {

    public:
      Melangeur(int octets);
      ~Melangeur();
      void inserer(const void* elem);
      void retirer(void* elem);
      void vider();
      int taille();

      int taille_elt;
      int nb_elt;
      std::vector<void*> vec;
      
      unsigned graine;
      std::default_random_engine generateur;

  };

} //end of namespace MMaze

#endif
