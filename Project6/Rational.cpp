#include "Rational.h"
#include "Polynomial.h"
#include <iostream>
using namespace std;

Rational::Rational() {
	denuminater.setCoeff(0, 1);

}
Rational :: ~Rational() {
}
Rational::Rational(Polynomial nom, Polynomial deom) :numinater(nom), denuminater(deom)
{
}
Polynomial Rational::getNom() const {
	return numinater;
}
Polynomial Rational::getDenom() const {
	return denuminater;
}
void Rational::print() const
{
	this->numinater.print();
	cout << "--------------------------" << endl;
	this->denuminater.print();
}