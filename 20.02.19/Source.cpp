#include <iostream>
#include <math.h>
#include "Input.h"

using namespace std;

int inputDimension();
float* inputArray(int);
int* sort(float*, int);
int digitInNum(int, int);
void output(float*, int*, int);

int main()
{
	int n = inputDimension();
	float *ptr = inputArray(n);
	output(ptr, sort(ptr, n), n);

	return 0;
}

float* inputArray(int n)
{
	float *ptr = new float[n];
	dynamicArrayInput(ptr, n);
	return ptr;
}

int inputDimension()
{
	int n;
	while (true)
	{
		cout << "Dimension of array:" << endl;
		cin >> n;
		if (n > 0)
		{
			return n;
		}
		cout << "Number of terms should be greater then 0!" << endl;
		system("cls");
	}
}

int* sort(float* ptr, int n)
{

	for (int i = 0; i < n; ptr++, i++)
	{
		*ptr = trunc(*ptr);
	}

	ptr -= n;

	for (int i = 0; i < n; ptr++, i++)
	{
		float num_10 = *ptr,
			num_2 = 0;
		int j = 1;
		while (num_10)
		{
			num_2 += j * ((int)num_10 % 2);
			num_10 = (int)num_10 / 2;
			j *= 10;
		}
		*ptr = num_2;
	}

	ptr -= n;

	int * resultPtr = new int[n];

	for (int i = 0; i < n; ptr++, resultPtr++, i++)
	{
		*resultPtr = (int)*ptr;
	}

	ptr -= n;
	resultPtr -= n;

	for (int i = 0; i < n; i++)
	{
		int current = digitInNum(*(resultPtr + i), 1),
			difference = 0;
		for(int j = 0; j < n - i; j++)
		{
			if(current > digitInNum(*(resultPtr + i + j), 1))
			{
				current = digitInNum(*(resultPtr + i + j), 1);
				difference = j;
			}
		}

		int temp = *(resultPtr + i);
		*(resultPtr + i) = *(resultPtr + i + difference);
		*(resultPtr + i + difference) = temp;
	}

	return resultPtr;

}

int digitInNum(int num, int digit)
{
	int result = 0;

	while (num)
	{
		if (num % 10 == digit)
		{
			result++;
		}

		num /= 10;
	}

	return result;
}

void output(float *ptr, int *resultPtr, int n)
{
	cout << "Source array:" << endl;
	for (int i = 1; i <= n; ptr++, i++)
	{
		cout << '[' << i << "] = ";
		cout << *ptr << endl;
	}

	cout << endl << "Result:" << endl;
	for (int i = 1; i <= n; resultPtr++, i++)
	{
		cout << '[' << i << "] = ";
		cout << *resultPtr << endl;
	}
}