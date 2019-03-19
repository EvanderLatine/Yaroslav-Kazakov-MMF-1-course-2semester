#include <iostream>
#include "customIO.h"

using namespace std;

int findMax(int *array, const int &dimension);

int findMax(int *array, const int &dimension)
{
	int max = *array;

	for (int i = 0; i < dimension; i++, array++)
	{
		if (max < *array)
		{
			max = *array;
		}
	}

	array -= dimension;

	return max;
}

int* Input::initialisation(const int &dimension, arrInit inputType) {
	int *arrPtr = new int[dimension];
	int max = 0;

	while (!max)
	{
		cout << "Maximal element of an array mustn't be equal to 0" << endl;

		for (int i = 0; i < dimension; i++)
		{
			arrPtr[i] = inputType(i);
		}

		max = findMax(arrPtr, dimension);
	}


	system("cls");

	return arrPtr;
}

int Input::inputDimension()
{
	int dimension;
	cout << "Please, input dimension of your array" << endl << "Dimension = ";
	cin >> dimension;
	system("cls");
	return dimension;
}

int Input::userInput(int position)
{
	int number;
	cout << "[" << position + 1 << "] = ";
	cin >> number;
	cout << endl;
	return number;
}

void Output::printArr(const int &dimension, int *array)
{
	for (int i = 0; i < dimension; i++, array++)
	{
		cout << "[" << i << "] " << *array << '\t';
	}
	cout << endl;
}

void Output::printArr(int &dimension, int *array)
{
	for (int i = 0; i < dimension; i++, array++)
	{
		cout << "[" << i << "] " << *array << '\t';
	}
	cout << endl;
}
