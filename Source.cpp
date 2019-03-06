#include <iostream>
#include "Input.h"

using namespace std;
using namespace Input;

int* select(int *dimension, int *newDimension, int *array);
bool selection(int elem, int max);
int* findMax(int *array, int *dimension);
int* findMin(int *array, int *dimension);
int compare(const void *a, const void *b);
void printArr(int *dimension, int *array);
void findNewDimension(int *dimension, int *newDimension, int *array);

int main()
{
	int *dimension = new int, *newDimension = new int;
	*dimension = inputDimension();
	*newDimension = 0;
	int *array = new int[*dimension];
	array = initialisation(dimension, &userInput);
	findNewDimension(dimension, newDimension, array);
	printArr(dimension, array);
	printArr(newDimension, select(dimension, newDimension, array));

	return 0;
}

int* select(int *dimension, int *newDimension, int *array)
{
	int *max = findMax(array, dimension);
	array -= *dimension;
	int *newArray = new int[*newDimension];

	for (int i = 0; i < *dimension - 1; i++, array++)
	{
		if (selection(*array, *max))
		{
			*newArray = *(array + 1);
			newArray++;
		}
	}

	array -= *dimension;
	newArray -= *newDimension;

	int *min = findMin(newArray, newDimension);
	max = findMax(newArray, newDimension);


	qsort(newArray, *newDimension, sizeof(*array), compare);

	return newArray;
}

bool selection(int elem, int max)
{
	if (max % elem == 0)
	{
		return true;
	}

	return false;
}

int* findMax(int *array, int *dimension)
{
	int *max = array;

	for (int i = 0; i < *dimension; i++, array++)
	{
		if (*max < *array)
		{
			*max = *array;
		}
	}

	return max;
}

int* findMin(int *array, int *dimension)
{
	int *min = array;

	for (int i = 0; i < *dimension; i++, array++)
	{
		if (*min > *array)
		{
			*min = *array;
		}
	}
	array -= *dimension * 2;

	return min;
}

int compare(const void *a, const void *b)  
{
	return (*(int*)a - *(int*)b);             
}

void printArr(int *dimension, int *array)
{
	for (int i = 0; i < *dimension; i++, array++)
	{
		cout << "[" << i << "] " << *array << '\t';
	}
	cout << endl;
}

void findNewDimension(int *dimension, int *newDimension, int *array)
{
	int *max = findMax(array, dimension);
	array -= *dimension;

	for (int i = 0; i < *dimension; i++, array++)
	{
		if (selection(*array, *max))
		{
			(*newDimension)++;
		}
	}
}