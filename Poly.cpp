#include "Poly.h"

Polynomial::Polynomial(double free = 0){
  if(free != 0)
    this->terms[0] = free;
}

std::ostream& Polynomial::operator<<(std::ostream&, const Polynomial&){
  
}