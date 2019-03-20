#include <iostream>
#include "customIO.h"

using namespace std;
using namespace Input;
using namespace Output;

int* select(const int &dimension, int &newDimension, int *array);
bool selection(int elem, int max);
int findMax(int *array, const int &dimension);
void findNewDimension(const int &dimension, int &newDimension, int *array);
void qSort(int[], int left, int right);
int partition(int[], int left, int right);

int main()
{
	const int &dimension = inputDimension();
	int newDimension = 0;
	int &newDim = newDimension;
	int *array = new int[dimension];
	array = initialisation(dimension, userInput);
	findNewDimension(dimension, newDimension, array);
	printArr(dimension, array);
	printArr(newDimension, select(dimension, newDimension, array));

	return 0;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}

	swap(arr[i + 1], arr[right]);
	return i + 1;
}

void qSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int newPivot = partition(arr, left, right);

		qSort(arr, left, newPivot - 1);
		qSort(arr, newPivot + 1, right);
	}
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

	qSort(newArray, 0, newDimension - 1);

	return newArray;
}

bool selection(int elem, int max)
{
	return !(elem % max);
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
