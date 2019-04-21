#pragma once

namespace Input
{
	typedef int(*arrInit)(int);

	int* initialisation(const int &dimension, arrInit);
	int inputDimension();
	unsigned int dimensionFromFile(const char*);
	int userInput(int position);
	void inputFromFile(const char*, int*);

}

namespace Output
{
	void printArr(int &dimension, int *array);
	void printArr(const int &dimension, int *array);
	void outputToFile(const char*, int *const, const int);
}
