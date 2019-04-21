#include <iostream>
#include<fstream>
#include "customIO.h"

using namespace std;


int findMax(int* array, const int& dimension)
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

int* Input::initialisation(const int& dimension, arrInit inputType) {
	int* arrPtr = new int[dimension];
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

unsigned int Input::dimensionFromFile(const char* pass)
{
	ifstream streamIn(pass);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	unsigned int count = 0, term;

	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}

	streamIn.close();

	return count;
}

int Input::userInput(int position)
{
	int number;
	cout << "[" << position + 1 << "] = ";
	cin >> number;
	cout << endl;
	return number;
}

void Input::inputFromFile(const char* pass, int* arrayPtr)
{
	unsigned int count = dimensionFromFile(pass);

	ifstream streamIn(pass);

	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}

	streamIn.close();

	int* array = new int[count]{ '\0' };
	int term;

	streamIn.open(pass, ios::in);

	for (unsigned int i = 0; i < count; i++)
	{
		streamIn >> term;
		array[i] = term;
	}

	streamIn.close();

	for (unsigned int i = 0; i < count; i++)
	{
		arrayPtr[i] = array[i];
	}
}

void Output::printArr(const int& dimension, int* array)
{
	for (int i = 0; i < dimension; i++, array++)
	{
		cout << "[" << i << "] " << *array << '\t';
	}
	cout << endl;
}

void Output::outputToFile(const char* pass, int* const array, const int dimension)
{
	ofstream streamOut;
	streamOut.open(pass, ios::app);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	streamOut << '\n';

	for (int i = 0; i < dimension; i++)
	{
		int temp = array[i];
		cout << "[" << i << ']' << " : ";
		streamOut.width(5);
		streamOut << temp;
		cout << temp << ' ';
	}

	cout << endl;

	streamOut.close();
}

void Output::printArr(int& dimension, int* array)
{
	for (int i = 0; i < dimension; i++, array++)
	{
		cout << "[" << i << "] " << *array << '\t';
	}
	cout << endl;
}
