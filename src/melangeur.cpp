#include "melangeur.hpp"

namespace MMaze {

  Melangeur::Melangeur(int octets) {
    taille_elem = octets;
    graine = std::chrono::system_clock::now().time_since_epoch().count();
    generateur = std::default_random_engine(graine);
  }

  Melangeur::~Melangeur() {
    vider();
  }

  void Melangeur::inserer(const void* elem) {
    vec.push_back(operator new(taille_elem));
    std::memcpy(vec.back(), elem, taille_elem);
  }

  void Melangeur::inserer(const std::vector<void*> & v_elem) {
    for (unsigned int i = 0; i < v_elem.size(); ++i) {
      inserer(v_elem[i]);
    }
  }

  void Melangeur::retirer(void* elem) {
    // Choix aléatoire de l'élément à retirer
    std::uniform_int_distribution<int> distribution(0, taille()-1);
    int aleatoire = distribution(generateur);

    std::memcpy(elem, vec[aleatoire], taille_elem);
    operator delete(vec[aleatoire]);
    vec[aleatoire] = vec.back();
    vec.pop_back();
  }

  void* Melangeur::retirer() {
    // Choix aléatoire de l'élément à retirer
    std::uniform_int_distribution<int> distribution(0, taille()-1);
    int aleatoire = distribution(generateur);

    void* elem = operator new(taille_elem);
    std::memcpy(elem, vec[aleatoire], taille_elem);
    operator delete(vec[aleatoire]);
    vec[aleatoire] = vec.back();
    vec.pop_back();
    
    return elem;
  }

  void Melangeur::vider() {
    for (unsigned int i = 0; i < vec.size(); ++i) {
      operator delete(vec[i]);
    }
    vec.clear();
  }

  int Melangeur::taille() {
    return vec.size();
  }

} //end of namespace MMaze
