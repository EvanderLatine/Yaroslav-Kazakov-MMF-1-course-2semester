#pragma once

using namespace std;

void dynamicArrayInput(float*, int);

void dynamicArrayInput(float *ptr, int n)
{
	for (int i = 1; i <= n; ptr++, i++)
	{
		cout << '[' << i << "] = ";
		cin >> *ptr;
		cout << endl;
	}
}
