//#pragma once
#include <iostream>
#include <map>

class Poly{
public:
  Poly(double free = 0); 
 // ~Poly();
  double& operator[](unsigned long i);
  double operator[](unsigned long i) const;
  double operator() (double x) const;
  
  friend std::ostream& operator<<(std::ostream& out, const Poly& poly);
  Poly operator-() const;
  friend Poly operator+(const Poly& a, const Poly& b);
  friend Poly operator-(const Poly& a, const Poly& b);
  friend Poly operator*(const Poly& a, const Poly& b);
  Poly operator+=(const Poly& a);
  Poly operator-=(const Poly& a);
  Poly operator*=(const Poly& a);
private:
  std::map<long, double> terms;
};
