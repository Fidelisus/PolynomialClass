#include "Poly.h"
#include "math.h"

Poly::Poly(double free){
  if(free != 0)
    this->terms[0] = free;
}

double& Poly::operator[](unsigned long i){
  return this->terms[i];
}

double Poly::operator[](unsigned long i) const{
  return this->terms.at(i);
}

std::ostream& operator<<(std::ostream& out, const Poly& poly){
  for(auto iterator = poly.terms.rbegin(); iterator != poly.terms.rend(); iterator++){
    if(iterator->second >= 0 && iterator->first != poly.terms.rbegin()->first) out << "+";
    if(iterator->second != 1 && iterator->second != -1) out << iterator->second;
    if(iterator->second == -1) out << "-";
    if(iterator->first == 1) out << "x ";
    if(iterator->first > 1) out << "x^" << iterator->first << " ";
  }
  return out;
}

Poly operator+(const Poly& a, const Poly& b){
  Poly sum = a;
  for(auto element : b.terms){
    sum[element.first] += element.second;
    if(element.second == 0)
      sum.terms.erase(element.first);
  }
return sum;
}

Poly Poly::operator-() const{
  Poly negation = *this;
  for(auto element : negation.terms){
    negation[element.first] = -element.second;
    if(element.second == 0)
      negation.terms.erase(element.first);
  }
return negation;
}

Poly operator-(const Poly& a, const Poly& b){
  Poly diff = -a+b;
  for(auto element : diff.terms){
    if(element.second == 0)
      diff.terms.erase(element.first);
  }

  return diff;
}

Poly operator*(const Poly& a, const Poly& b){
  Poly multi;

  for(auto elementa : a.terms){
    for(auto elementb : b.terms){
    multi[elementa.first + elementb.first] += elementa.second * elementb.second;
    if(elementa.second * elementb.second == 0)
      multi.terms.erase(elementa.first + elementb.first);
    }
  }
  return multi;
}

Poly Poly::operator+=(const Poly& a){
  return *this = *this+a;
}

Poly Poly::operator-=(const Poly& a){
  return *this = *this-a;
}

Poly Poly::operator*=(const Poly& a){
  return *this = *this*a;
}

double Poly::operator() (double x) const{
  double sum = 0;
    for(auto element : this->terms){
      sum += element.second * pow(x, element.first);
    }
  return sum;
}