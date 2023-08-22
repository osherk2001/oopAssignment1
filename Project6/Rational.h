#pragma once
#include "Polynomial.h"
#include<iostream>

class Rational
{
private:
	Polynomial numinater;
	Polynomial denuminater;
public:
	Rational();
	Rational(Polynomial, Polynomial);
	~Rational();
	void print() const;
	Polynomial getNom() const;
	Polynomial getDenom() const;

};
