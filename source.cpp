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
	void print() const {
		std::cout << real << "+i*(" << imag << ")" << std::endl;
	}
	~Complex() {
		std::cout << "Killed: " << real << ", " << imag << std::endl;
	}

	Complex operator - (const Complex &Y) const {
		return Complex(this->real - Y.real, this->imag - Y.imag);
	}

	Complex & operator = (const Complex &X) {
		if (this != &X) {
			this->real = X.real;
			this->imag = X.imag;
		}
		return *this;
	}
};

std::ostream& operator << (std::ostream& out, const Complex &X) {
	out << X.re();
	if (X.im() >= 0)
		out << '+';
	out << X.im() << "*i";
	return out;
}

Complex operator + (const Complex &X, const Complex &Y) {
	return Complex(X.re() + Y.re(), X.im() + Y.im());
}

double Complex::abs() const { 
	return sqrt(real*real + imag * imag); 
}

int main() {

	Complex X(2.0, 2.0);
	Complex Y(1.0, 5.0);
	Complex *p = &X;
	X = *p;
	return 0;
}
