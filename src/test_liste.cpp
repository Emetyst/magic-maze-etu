#include "liste.hpp"

#include <iostream>
#include <cassert>

int main() {

  /* adaptez ce fichier selon votre structure */

  Liste l1 ;
  l1.ajouter_en_tete(10) ;
  l1.ajouter_en_tete(11) ;
  std::cout << "attendu : [ 11 10 ]" << std::endl ;
  l1.afficher() ; // [ 11 10 ]
  assert(l1.tete()->valeur == 11) ;
  assert(l1.queue()->valeur == 10) ;
  assert(l1.recherche(11)) ;
  assert(l1.recherche(10)) ;
  assert(!l1.recherche(12)) ;
  assert(l1.taille() == 2) ;
  
  Liste l2(l1) ;
  l2.ajouter_en_tete(20) ;
  std::cout << "attendu : [ 20 11 10 ]" << std::endl ;
  l2.afficher() ; // [ 20 11 10 ]
  assert(l2.tete()->valeur == 20) ;
  assert(l2.queue()->valeur == 10) ;
  assert(l2.recherche(20)) ;
  assert(l2.recherche(11)) ;
  assert(l2.recherche(10)) ;
  assert(!l2.recherche(21)) ;

  Liste l3 ;
  l3.ajouter_en_tete(30) ;
  l3 = l1 ;
  std::cout << "attendu : [ 11 10 ]" << std::endl ;
  l3.afficher() ; // [ 11 10 ]
  assert(l3.tete()->valeur == 11) ;
  assert(l3.queue()->valeur == 10) ;
  assert(l3.recherche(11)) ;
  assert(l3.recherche(10)) ;
  assert(!l3.recherche(30)) ;

  l1.supprimer_en_tete() ;
  l1.afficher() ; // [ 10 ]
  assert(l1.tete()->valeur == 10) ;
  assert(l1.queue()->valeur == 10) ;
  assert(l1.recherche(10)) ;
  assert(!l1.recherche(11)) ;

  l1.ajouter_en_tete(12) ;
  std::cout << "attendu : [ 12 10 ]" << std::endl ;
  l1.afficher() ; // [ 12 10 ]
  assert(l1.tete()->valeur == 12) ;
  assert(l1.recherche(10)) ;

  std::cout << "attendu : [ 20 11 10 ]" << std::endl ;
  l2.afficher() ; // [ 20 11 10 ]
  assert(l2.tete()->valeur == 20) ;
  assert(l2.recherche(11)) ;
  assert(l2.recherche(10)) ;

  std::cout << "attendu : [ 11 10 ]" << std::endl ;
  l3.afficher() ; // [ 11 10 ]
  assert(l3.tete()->valeur == 11) ;
  assert(l3.recherche(10)) ;

  l3.ajouter_en_queue(31) ;
  std::cout << "attendu : [ 11 10 31 ]" << std::endl ;
  l3.afficher() ; // [ 11 10 31 ]
  assert(l3.tete()->valeur == 11) ;
  assert(l3.queue()->valeur == 31) ;
  assert(l3.recherche(11)) ;
  assert(l3.recherche(10)) ;
  assert(l3.recherche(31)) ;

  Liste l4({0, 1, 3, -5, 7});
  std::cout << "attendu : [ 0 1 3 -5 7 ]" << std::endl;
  l4.afficher();
  std::cout << std::endl << "Avec cout : " << l4 << std::endl;

  l4.concatener(l3);
  std::cout << "l4.concatener(l3) :" << l4 << std::endl;
  std::cout << "l3" << l3 << std::endl;

  return 0 ;
}