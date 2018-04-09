#include "liste.hpp"

Liste::Liste() {
  init_attributs();
}

Liste::Liste(const Liste& autre) {
  init_attributs();
  copier(autre);
}

Liste::Liste(const std::vector<int> & v_elem) {
  init_attributs();
  for (unsigned int i = 0; i < v_elem.size(); i++) {
    ajouter_en_queue(v_elem[i]);
  }
}

Liste& Liste::operator=(const Liste& autre) {
  // On supprime d'abord le contenu actuel de la liste
  vider();
  copier(autre);
  return *this;
}

Liste::~Liste() {
  vider();
}

void Liste::ajouter_en_tete(int valeur) {
  Cellule* c = new Cellule(valeur, first);
  first = c;
  if (taille() == 0) last = c;
  size++;
}

void Liste::ajouter_en_queue(int valeur) {
  // L'ajout en queue se fait en temps constant
  Cellule* c = new Cellule(valeur);
  if (taille() == 0) first = c;
  else last->next = c;
  last = c;
  size++;
}

void Liste::concatener(const Liste& autre) {
  copier(autre);
}

void Liste::supprimer_en_tete() {
  if (taille() != 0) {
    Cellule* tmp = first;
    first = first->next;
    delete tmp;
    size--;
    if (taille() == 0) last = nullptr;
  }
}

Cellule* Liste::tete() {
  return first;
}

const Cellule* Liste::tete() const {
  return (const Cellule*) first;
}

Cellule* Liste::queue() {
  return last;
}

const Cellule* Liste::queue() const {
  return (const Cellule*) last;
}

int Liste::taille() const {
  return size;
}

Cellule* Liste::recherche(int valeur) {
  if (taille() == 0) return nullptr;
  else {
    Cellule* tmp = first;
    while (tmp != nullptr) {
      if (tmp->valeur == valeur) break;
      tmp = tmp->next;
    }
    return tmp;
  }
}

const Cellule* Liste::recherche(int valeur) const {
  if (taille() == 0) return nullptr;
  else {
    Cellule* tmp = first;
    while (tmp != nullptr) {
      if (tmp->valeur == valeur) break;
      tmp = tmp->next;
    }
    return (const Cellule*) tmp;
  }
}

void Liste::afficher() const {
  std::cout << "[";
  if (taille() != 0) {
    std::cout << " ";
    Cellule* tmp = first;
    while (tmp != nullptr) {
      std::cout << tmp->valeur << " ";
      tmp = tmp->next;
    }
  }
  std::cout << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Liste& t) {
  out << "[";
  if (t.taille() != 0) {
    out << " ";
    Cellule* tmp = t.first;
    while (tmp != nullptr) {
      out << tmp->valeur << " ";
      tmp = tmp->next;
    }
  }
  out << "]";
  return out;
}

void Liste::vider() {
  while (taille() != 0) {
    supprimer_en_tete();
  }
}

void Liste::copier(const Liste& autre) {
  Cellule* tmp = (Cellule*) autre.tete();
  while (tmp != nullptr) {
    ajouter_en_queue(tmp->valeur);
    tmp = tmp->next;
  }
}

void Liste::init_attributs() {
  first = nullptr;
  last = nullptr;
  size = 0;
}