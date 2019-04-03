#pragma once
#include<iostream>

using namespace std;

class Fraction {
public:
	Fraction(int a, unsigned int b);

	void setNumerator(int);
	void setDenominator(unsigned int);

	int getNumerator() const;
	int getDenominator() const;

	void consoleFraction() const;
	bool isProper() const;
	bool isMixed() const;
	bool isEqualTo(Fraction) const;
	void fractionSign() const;

private:
	int numerator;
	unsigned int denominator;

};