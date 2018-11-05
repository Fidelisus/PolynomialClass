#pragma once
#include <iostream>

class Polynomial{
public:
  Polynomial(double free = 0); 
  ~Polynomial();
  double operator[](long);
  
  friend std::ostream& operator<<(std::ostream&, const Polynomial&);
  Polynomial operator-();
  friend Polynomial operator+(const Polynomial&, const Polynomial&);
  friend Polynomial operator-(const Polynomial&, const Polynomial&);
  friend Polynomial operator*(const Polynomial&, const Polynomial&);
  Polynomial operator+=(const Polynomial&);
  Polynomial operator-=(const Polynomial&);
  Polynomial operator*=(const Polynomial&);
private:
  std::map<long, double> terms;
}
