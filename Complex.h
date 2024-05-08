#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
	double a;
	double b;

public:
	Complex();
	Complex(double real, double im);

	double get_a();
	double get_b();

	void set_a(double real);
	void set_b(double imag);


	bool operator>(const Complex& other) const;
	friend Complex operator--(Complex& other);
	friend Complex operator--(Complex& other, int notused);
	void operator=(const Complex& other);


	void print();
};

Complex operator-(Complex& main, Complex& other);


#endif COMPLEX_H
