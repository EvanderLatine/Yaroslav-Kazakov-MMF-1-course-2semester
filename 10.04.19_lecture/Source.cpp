#include"DynamicArray.h"
#include<iostream>

using namespace std;

void console(const DynamicArray&);

int main()
{
	DynamicArray array1;

	array1.add(1);
	array1.add(5);
	array1.add(7);
	array1.add(2);
	//array1.add(5);

	for (int i = 0; i < array1.getLength(); i++)
	{
		cout << array1.getArray()[i] << '\t';
	}

	DynamicArray array2(8);
	DynamicArray array3(array1);
	console(array1);
	array1.getLength();
	console(array2);


	return 0;
}

void console(const DynamicArray &array)
{
	cout << array.getLength();
}