#include "melangeur.hpp"

namespace MMaze {

  Melangeur::Melangeur(int octets) {
    taille_elt = octets;
    nb_elt = 0;
  }

  Melangeur::~Melangeur() {
    vider();
  }

  void Melangeur::inserer(const void* elem) {
    vec.push_back((void*) malloc(taille_elt));
    std::memcpy(vec.back(), elem, taille_elt);
    nb_elt++;
  }

  void Melangeur::retirer(void* elem) {
    std::srand(std::time(nullptr));
    int aleatoire = std::rand() % nb_elt;
    std::memcpy(elem, vec[aleatoire], taille_elt);
    free(vec[aleatoire]);
    vec.erase(vec.begin() + aleatoire);
    nb_elt--;
  }

  void Melangeur::vider() {
    for (unsigned int i = 0; i < vec.size(); i++) {
      free(vec[i]);
    }
  }

  int Melangeur::taille() {
    return nb_elt;
  }

} //end of namespace MMaze
