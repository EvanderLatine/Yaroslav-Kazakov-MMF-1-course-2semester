#pragma once

namespace Input
{
	typedef int(*arrInit)(int);

	int* initialisation(int *dimension, arrInit);
	int inputDimension();
	int userInput(int position);
}
