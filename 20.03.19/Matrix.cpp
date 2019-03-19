#include<iostream>
#include<cstdlib>
#include <cmath>
#include"Matrix.h"

using namespace std;

void matrix::initialiseMatrix(double** matrix, const int coloumnsDimension, ElementIninialisation initialisationFunction, const double accuracy)
{
	for (unsigned int i = 1; i <= coloumnsDimension; i++)
	{
		for (unsigned int j = 0; j < matrix[0][i - 1]; j++)
		{
			matrix[i][j] = initialisationFunction(accuracy, i, j + 1);
		}
	}
}

double** matrix::allocateMatrixMemory(const int coloumnsDimension, int *const rowDimensions)
{
	double ** const matrix = new double*[coloumnsDimension + 1];

	matrix[0] = new double[coloumnsDimension];

	for (unsigned int i = 0; i < coloumnsDimension; i++)
	{
		matrix[0][i] = rowDimensions[i];
	}

	for (unsigned int i = 1; i <= coloumnsDimension; i++)
	{
		matrix[i] = new double[matrix[0][i - 1]];
	}

	return matrix;
}

const int matrix::setDimension()
{
	int dimension;
	cin >> dimension;

	system("cls");

	return dimension;
}

void matrix::setRowDimensions(int* dimensionsMatrix, const int coloumnsDimension)
{
	for (unsigned int i = 0; i < coloumnsDimension; i++)
	{
		cout << "Number of elements in " << i + 1 << " row: ";

		dimensionsMatrix[i] = setDimension();
	}
}

const double matrix::customElement(const double accuracy, const int i, const int j)
{
	return i == 2 * j ? (sin(2 * i * j, accuracy) + sin(i, accuracy)) / ((i - j - 4) * (i - j - 4) * (i - j - 4) + (i + j) * (i + j)) : i;
}

const double matrix::builtInElement(const double accuracy, const int i, const int j)
{
	return i == 2 * j ? (sin(2 * i * j) + sin(i)) / ((i - j - 4) * (i - j - 4) * (i - j - 4) + (i + j) * (i + j)) : i;
}

const double matrix::setAccuracy()
{
	double accuracy = 0;

	while (!(accuracy > 0 && accuracy <= 1))
	{
		cout << "Setting accuracy of matrix elements. Please, input positive real number x(0 , 1)." << endl << "x = ";
		cin >> accuracy;
		system("cls");
	}

	return accuracy;
}

const int matrix::compareMatrix(double **const firstMatrix, double **const secondMatrix, const int coloumnsDimension)
{
	const double difference = computeMatrixDifference(firstMatrix, secondMatrix, coloumnsDimension);

	cout << "Maximum difference between two matrix elements: " << difference << endl;

	if (difference > 0)
	{
		return 1;
	}
	else if (difference < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

const double matrix::computeMatrixDifference(double **const firstMatrix, double **const secondMatrix, const int coloumnsDimension)
{
	double maxDifference = 0;

	for (unsigned int i = 1; i <= coloumnsDimension; i++)
	{
		for (unsigned int j = 0; j < firstMatrix[0][i - 1]; j++)
		{
			double difference = firstMatrix[i][j] - secondMatrix[i][j];

			if (abs(difference) > abs(maxDifference))
			{
				maxDifference = difference;
			}
		}
	}

	return maxDifference;
}

void matrix::displayMatrix(double **const matrix, const int coloumnsDimension)
{
	for (unsigned int i = 1; i <= coloumnsDimension; i++)
	{
		for (unsigned j = 0; j < matrix[0][i - 1]; j++)
		{
			cout << matrix[i][j] << "\t\t";
		}

		cout << endl;
	}

	cout << endl;
}

double sin(double arg, const double accuracy)
{
	const double PI = 3.14159265358979323846;
	double argument = arg;
	argument = fmod(argument, PI * 2);


	int sign = -1, i = 1;
	double x = argument * argument * argument;
	double previousResult = 0, result = argument;

	while (abs(result - previousResult) > accuracy)
	{
		previousResult = result;
		result += sign * x / factorial(2 * (i + 1) - 1);
		sign *= -1;
		x *= argument * argument;
		i++;
	}

	return result;
}

const long long factorial(const long argument)
{
	if (!argument)
	{
		return 1;
	}

	long long factorial = 1;

	for (int i = 1; i <= argument; i++)
	{
		factorial *= i;
	}

	return factorial;
}
