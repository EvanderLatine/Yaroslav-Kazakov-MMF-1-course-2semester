#include <iostream>
#include "Input.h"

using namespace std;

int* Input::initialisation(int *dimension, arrInit inputType) {
	int *arrPtr = new int[*dimension];

	for (int i = 0; i < *dimension; i++)
	{
		arrPtr[i] = inputType(i);
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

