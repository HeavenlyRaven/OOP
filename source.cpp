#include "stdafx.h"
#include <iostream>

class Complex {
private:
	double real, imag;
public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
	double re() const { return real; }
	double im() const { return imag; }
	double& re() { return real; }
	double& im() { return imag; }
	inline double abs() const;

};

std::ostream& operator << (std::ostream& out, const Complex &X) {
	out << X.re();
	if (X.im() >= 0)
		out << '+';
	out << X.im() << "*i";
	return out;
}

double Complex::abs() const { return sqrt(real*real + imag * imag); }

int main() {

	Complex X(2.0, 2.0);
	const Complex Y(1.0, 5.0);
	std::cout << X << std::endl;
	std::cout << Y << std::endl;
	X.re() = 6.0;
	std::cout << X << std::endl;

	return 0;
}
