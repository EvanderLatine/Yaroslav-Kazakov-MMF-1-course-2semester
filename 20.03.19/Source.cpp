#include<iostream>
#include"Matrix.h"

using namespace std;
using namespace matrix;

void displayingResult(const int);

int main()
{
	cout << "Number of coloumns: " << endl;
	const int coloumnsDimension = setDimension();

	int *rowDimensions = new int[coloumnsDimension];
	setRowDimensions(rowDimensions, coloumnsDimension);

	const double accuracy = setAccuracy();


	double ** const firstMatrix = allocateMatrixMemory(coloumnsDimension, rowDimensions);
	initialiseMatrix(firstMatrix, coloumnsDimension, customElement, accuracy);

	double ** const secondMatrix = allocateMatrixMemory(coloumnsDimension, rowDimensions);
	initialiseMatrix(secondMatrix, coloumnsDimension, builtInElement, accuracy);


	displayMatrix(firstMatrix, coloumnsDimension);
	displayMatrix(secondMatrix, coloumnsDimension);
	displayingResult(compareMatrix(firstMatrix, secondMatrix, coloumnsDimension));

	return 0;
}

void displayingResult(const int result)
{
	if (result > 0)
	{
		cout << "First matrix is greater than the second." << endl;
	}
	else if (result < 0)
	{
		cout << "Second matrix is greater than the first." << endl;
	}
	else
	{
		cout << "Matrices are equal." << endl;
	}
}

