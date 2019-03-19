#pragma once

namespace Input
{
	typedef int(*arrInit)(int);

	int* initialisation(const int &dimension, arrInit);
	int inputDimension();
	int userInput(int position);

}

namespace Output
{
	void printArr(int &dimension, int *array);
	void printArr(const int &dimension, int *array);
}
