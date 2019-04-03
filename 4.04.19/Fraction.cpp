#include<iostream>
#include"Fraction.h"

using namespace std;

Fraction::Fraction(int n, unsigned int d)
{
	setNumerator(n);
	setDenominator(d);
	
	try
	{
		if (!(abs(numerator) % denominator))
		{
			throw "This numerator and denominator doesn't setting fraction. Result of division numerator upon denominator is integer.";
		}
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
}

#pragma region setters
void Fraction::setNumerator(int n)
{
	numerator = n;
}

void Fraction::setDenominator(unsigned int d)
{
	denominator = d;
}
#pragma endregion

#pragma region getters
int Fraction::getNumerator() const
{
	return numerator;
}

int Fraction::getDenominator() const
{
	return denominator;
}
#pragma endregion

# pragma region predicates
bool Fraction::isProper() const
{
	return numerator < denominator;
}

bool Fraction::isMixed() const
{
	return numerator > denominator;
}

bool Fraction::isEqualTo(Fraction toCompate) const
{
	return (toCompate.getNumerator() == numerator && toCompate.getDenominator() == denominator);
}
#pragma endregion

void Fraction::consoleFraction() const
{
	cout << numerator << "/" << denominator << endl;
}

void Fraction::fractionSign() const
{
	if (numerator > 0)
	{
		cout << "Fraction is positive." << endl;
	}
	else if (numerator < 0)
	{
		cout << "Fraction is negative." << endl;
	}
	else
	{
		cout << "Fraction is equal to zero." << endl;
	}
}






