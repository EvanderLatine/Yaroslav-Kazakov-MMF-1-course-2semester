#include <iostream>
#include "customIO.h"

using namespace std;
using namespace Input;
using namespace Output;

int* select(const int &dimension, int &newDimension, int *array);
bool selection(int elem, int max);
int findMax(int *array, const int &dimension);
int compare(const void *a, const void *b);
void findNewDimension(const int &dimension, int &newDimension, int *array);

int main()
{
	const int &dimension = inputDimension();
	int newDimension = 0;
	int &newDim = newDimension;
	int *array = new int[dimension];
	array = initialisation(dimension, &userInput);
	findNewDimension(dimension, newDimension, array);
	printArr(dimension, array);
	printArr(newDimension, select(dimension, newDimension, array));

	return 0;
}

int* select(const int &dimension, int &newDimension, int *array)
{
	int max = findMax(array, dimension);
	int *newArray = new int[newDimension];

	for (int i = 0; i < dimension - 1; i++, array++)
	{
		if (selection(*array, max))
		{
			*newArray = *(array + 1);
			newArray++;
		}
	}

	array -= dimension;
	newArray -= newDimension;

	qsort(newArray, newDimension, sizeof(*array), compare);

	return newArray;
}

bool selection(int elem, int max)
{
	if (elem % max == 0)
	{
		return true;
	}

	return false;
}

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

int compare(const void *a, const void *b)  
{
	return (*(int*)a - *(int*)b);             
}

void findNewDimension(const int &dimension, int &newDimension, int *array)
{
	int max = findMax(array, dimension);

	for (int i = 0; i < dimension - 1; i++, array++)
	{
		if (selection(*array, max))
		{
			newDimension++;
		}
	}
}