#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP

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
    void inserer(const std::vector<void*> & v_elem);
    void retirer(void* elem);
    void* retirer();
    void vider();
    int taille();

  private:
    std::vector<void*> vec;
    int taille_elem;
    unsigned graine;
    std::default_random_engine generateur;

};

} //end of namespace MMaze

#endif
