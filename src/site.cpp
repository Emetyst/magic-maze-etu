#include "site.hpp"

#include <iostream>

namespace MMaze {
    Site::Site(unsigned int li, unsigned int col, Couleur c, Type t) : Case(li, col) {
        
    }
    
    Site::Site(unsigned int index, Couleur c, Type t) : Case(index) {

    }
}