#pragma once
#include<iostream>

namespace matrix
{
	typedef const double(ElementIninialisation)(const double, const int, const int);

	const int setDimension();
	void setRowDimensions(int*, const int);
	const double setAccuracy();
	double** allocateMatrixMemory(const int, int *const);

	void initialiseMatrix(double**, const int, ElementIninialisation, const double);

	const double customElement(const double, const int, const int);
	const double builtInElement(const double, const int, const int);

	const int compareMatrix(double **const, double **const, const int);
	const double computeMatrixDifference(double **const, double **const, const int);

	void displayMatrix(double **const, const int);
}

double sin(double argument, const double accuracy);
const long long factorial(const long);