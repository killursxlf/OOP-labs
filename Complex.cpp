#include "Complex.h"

using namespace std;


double Complex::get_a() { return a; }
double Complex::get_b() { return b; }

void Complex::set_a(double real) { a = real; }
void Complex::set_b(double imag) { b = imag; }


Complex::Complex()
{
	a = 0.0;
	b = 0.0;
}

Complex::Complex(double real, double im)
{
	a = real;
	b = im;
}

bool Complex::operator>(const Complex& other) const
{
	return (abs(a) + abs(b)) > (abs(other.a) + abs(other.b));
}

Complex operator--(Complex& other)
{
	--other.a;
	--other.b;
	return other;
}

Complex operator--(Complex& other, int notused)
{
	Complex temp = other;
	--other.a;
	--other.b;
	return temp;
}

void Complex::print()
{
	cout << "Complex number: " << a << " + " << b << "i" << endl;
}

void Complex::operator=(const Complex& other)
{
	a = other.a;
	b = other.b;
}
