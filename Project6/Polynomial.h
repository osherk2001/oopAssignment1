#include<iostream>
#pragma once
using namespace std;
class Polynomial
{
private:
	int degree;
	int size;
	double* array;
	static int max_degree;
public:
	Polynomial(int = 0);
	Polynomial(double[], int);
	Polynomial(const Polynomial&);
	~Polynomial();
	int getDegree(bool)const;
	static int getMaxDegree();
	double getCoeff(int) const;
	void setCoeff(int, double);
	void print() const;

};