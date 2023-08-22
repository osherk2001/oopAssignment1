#include "Polynomial.h"
#include <iostream>
using namespace std;

int Polynomial::max_degree = 0;
Polynomial ::~Polynomial() {
	delete[]array;
};
Polynomial::Polynomial(const Polynomial& p) {
	this->degree = p.degree;
	this->size = p.size;
	this->array = new double[degree + 1];
	for (int i = 0; i <= size; i++)
	{
		this->array[i] = p.array[i];
	}
}
Polynomial::Polynomial(int _degree) {
	degree = 0;
	size = _degree;
	array = new double[degree + 1];
	for (int i = 0; i < degree + 1; i++)
		array[i] = 0;
}
Polynomial::Polynomial(double a[], int _degree) {
	size = _degree;
	int i = 0;
	while (a[_degree] == 0)_degree--;
	degree = _degree;
	array = new double[degree + 1];
	for (i = 0; i <= degree; i++)
	{
		array[i] = a[i];
	}
	if (max_degree < degree) max_degree = degree;
}
int Polynomial::getDegree(bool a)const
{
	if (a == false)
	{
		return size;
	}
	else
	{
		return degree;
	}
}
int Polynomial::getMaxDegree() {
	return max_degree;
}
double Polynomial::getCoeff(int index) const {
	if (index < 0 || index > getDegree(false))
		return 123456;;
	return array[index];
}
void Polynomial::setCoeff(int newCoeff, double value)
{
	int _size = getDegree(true) + 1;
	if (newCoeff > getDegree(true))
	{
		degree = newCoeff;
		double* temparray = new double[newCoeff + 1];
		int i = 0;

		for (i = 0; i < _size; i++)
			temparray[i] = array[i];
		for (i = _size; i < newCoeff; i++)
			temparray[i] = 0;
		temparray[newCoeff] = value;
		delete[] array;
		array = temparray;
	}
	else {
		if (newCoeff <= -1) {
			cout << "error" << endl;
			return;
		}
		array[newCoeff] = value;
	}
	if (max_degree < degree)max_degree = degree;
}
void Polynomial::print() const {
	int _size = (*this).getDegree(true) + 1;
	if (this->degree == 0 && array[0] == 0)
		cout << "Polynomial = 0" << endl;
	else {
		int i = 0;
		int flag = 0;//turn up only when meet a first non zero value
		for (i = 0; (i < _size && (flag == 0)); i++)
		{
			if (this->array[i] != 0)
			{
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "polynomial = 0" << endl;
		else
		{
			cout << "polynomial = " << this->array[0];
			for (i = 1; i < _size; i++)
			{
				if (this->array[i] >= 0)
					cout << "+" << this->array[i] << "x^" << i;
				else
					cout << this->array[i] << "x^" << i;

			}
			cout << endl;
		}
	}
}
