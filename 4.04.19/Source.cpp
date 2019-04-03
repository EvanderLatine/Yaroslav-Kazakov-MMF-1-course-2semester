#include<iostream>
#include"Fraction.h"

using namespace std;
typedef void (SortFunction)(Fraction*[], int, int, int (key)(Fraction *const));

const int setFractionsNumber();
int inputNumerator();
unsigned int inputDenominator();

Fraction *const choseFraction(Fraction*[], const int, bool (predicate)(Fraction *const));

Fraction **const keySort(Fraction*[], const int, SortFunction, int (key)(Fraction *const));
void mergeSort(Fraction*[], int, int, int (key)(Fraction *const));
void merge(Fraction*[], int, int, int, int (key)(Fraction *const));
void quickSort(Fraction*[], int, int, int (key)(Fraction *const));

bool isProper(Fraction *const);
int integerPart(Fraction *const);
Fraction** allocateMemoryForArray(int);
void swap(Fraction*, Fraction*);

void consoleFractions(Fraction **, const int);

void main()
{
	const int dimension = setFractionsNumber();
	Fraction **fractions = new Fraction*[dimension];

	for (unsigned int i = 0; i < dimension; i++)
	{
		fractions[i] = new Fraction(inputNumerator(), inputDenominator());
	}

//#pragma region firstPart
//	Fraction *const suitableFraction = choseFraction(fractions, dimension, isProper);
//	
//	cout << "Fraction that satisfies the condition: ";
//	suitableFraction->consoleFraction();
//#pragma endregion

#pragma region secondPart
	SortFunction **sortingFunctions = new SortFunction*[2];
	sortingFunctions[0] = mergeSort;
	sortingFunctions[1] = quickSort;

	cout << "Initial array:" << endl;
	consoleFractions(fractions, dimension);

	keySort(fractions, dimension, sortingFunctions[1], integerPart);

	cout << "Sorted array:" << endl;
	consoleFractions(fractions, dimension);

#pragma endregion
}

const int setFractionsNumber()
{
	cout << "How much fractions do you wanna create?" << endl;
	
	int dimension;
	cin >> dimension;

	return dimension;
}

bool isProper(Fraction *const fraction)
{
	return fraction->getNumerator() < fraction->getDenominator();
}

Fraction *const choseFraction(Fraction *fractions[], const int dimension, bool (predicate)(Fraction *const))
{
	for (unsigned int i = 0; i < dimension; i++)
	{
		if (predicate(fractions[i]))
		{
			return fractions[i];
		}
	}
}

void quickSort(Fraction *fractions[], int left, int right, int (key)(Fraction *const))
{
	if (fractions == nullptr)
	{
		throw std::invalid_argument("Matrix can not be null.");
	}
	int i = left, j = right;
	Fraction *pivot = fractions[(left + right) / 2];
	while (i <= j)
	{
		while (key(fractions[i]) < key(pivot))
		{
			i++;
		}
		while (key(fractions[j]) > key(pivot))
		{
			j--;
		}
		if (i <= j)
		{
			swap(fractions[i], fractions[j]);
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSort(fractions, left, j, key);
	}
	if (right > i)
	{
		quickSort(fractions, j, right, key);
	}
}

void mergeSort(Fraction *fractions[], int left, int right, int (key)(Fraction *const))
{
	if (fractions == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (left < 0 || right < 0)
	{
		throw std::invalid_argument("Left, mid and right parameters can not be less 0.");
	}

	int mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		mergeSort(fractions, left, mid, key);
		mergeSort(fractions, mid + 1, right, key);
		merge(fractions, left, mid, right, key);
	}
}

void merge(Fraction *fractions[], int left, int mid, int right, int (key)(Fraction *const))
{
	if (fractions == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (left < 0 || mid < 0 || right < 0)
	{
		throw std::invalid_argument("Left, mid and right parameters can not be less 0.");
	}

	int pos1 = left, pos2 = mid + 1, pos3 = 0;

	Fraction **temp = allocateMemoryForArray(right - left + 1);

	while (pos1 <= mid && pos2 <= right)
	{
		if (key(fractions[pos2]) < key(fractions[pos1]))
		{
			temp[pos3++] = fractions[pos1++];
		}
		else
		{
			temp[pos3++] = fractions[pos2++];
		}
	}

	while (pos2 <= right)
	{
		temp[pos3++] = fractions[pos2++];
	}
	while (pos1 <= mid)
	{
		temp[pos3++] = fractions[pos1++];
	}

	for (pos3 = 0; pos3 < right - left + 1; pos3++)
	{
		fractions[left + pos3] = temp[pos3];
	}

	delete[] temp;
}

Fraction ** allocateMemoryForArray(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Number of elements in an array can not be less or equal 0.");
	}

	Fraction** array = new Fraction*[n];
	return array;
}

Fraction **const keySort(Fraction *fractions[], const int dimension, SortFunction sortType, int (key)(Fraction *const))
{
	if (dimension <= 0)
	{
		throw std::invalid_argument("Number of elements in an array can not be less or equal 0.");
	}

	Fraction** fractionsCopy = new Fraction*[dimension];

	for (unsigned int i = 0; i < dimension; i++)
	{
		fractionsCopy[i] = fractions[i];
	}

	sortType(fractionsCopy, 0, dimension - 1, key);

	return fractionsCopy;
}

int integerPart(Fraction *const fraction)
{
	return fraction->getNumerator() / fraction->getDenominator();
}

void consoleFractions(Fraction ** fractions, const int dimension)
{
	for (unsigned int i = 0; i < dimension; i++)
	{
		fractions[i]->consoleFraction();
	}

	cout << endl;
}

int inputNumerator()
{
	cout << "Set numerator of the fraction:";

	int num;
	cin >> num;
	system("cls");
	
	return num;

}

unsigned int inputDenominator()
{
	cout << "Set denominator of the fraction:";

	int den;
	cin >> den;
	system("cls");

	return den;
}

void swap(Fraction *first, Fraction *second)
{
	Fraction temp = *first;
	*first = *second;
	*second = temp;
}