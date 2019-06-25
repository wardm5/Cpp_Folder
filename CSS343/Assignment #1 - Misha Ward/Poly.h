// ------------------------------------------------ Poly.h --------------------------------------------------------
// Misha Ward CSS 343 Section B
// January 11th 2018
// January 14th 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Methods to store, calculate, receive input, and show output of polynomials functions.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//    - Assumptions include: Input is limited to integers. No negative exponents.
// --------------------------------------------------------------------------------------------------------------------
using namespace std;
#include <iostream>

class Poly {
public: 
  Poly(); // poly default constructor
  Poly(int coefficent); // poly constructor for just passed in coef
  Poly(int coefficent, int exponet); // poly constructor for passed in coef and exponent
  Poly(const Poly& polyNomil); // poly constructor for passed in poly object
  void expandArray(int newSize); // expand array method
  ~Poly(); // poly deconstructor
  int getSize(); // returns the size of the array
  void setCoeff(int coefficent, int exponet); // set's the coef of the poly
  int getCoeff(int exponet); // gets the coef of the poly
  Poly operator+(Poly const &obj); // operator override of + operator
  Poly operator-(Poly const &obj); // operator override of - operator
  Poly operator*(Poly const &obj); // operator override of * operator
  Poly operator=(Poly const &obj); // operator override of = operator
  Poly operator+=(Poly const &obj); // operator override of += operator
  Poly operator-=(Poly const &obj); // operator override of -= operator
  Poly operator*=(Poly const &obj); // operator override of *= operator
  bool operator==(const Poly&) const; // operator override of == operator
  bool operator!=(const Poly&) const; // operator override of != operator

  int * array; // creates array pointer
  int size; // array size, since array does not have size function/method
};
ostream& operator<<(ostream& os, Poly& poly);
istream& operator>>(istream& ins, Poly& poly);
