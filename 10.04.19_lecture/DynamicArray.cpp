#include "DynamicArray.h"
#include<iostream>

using namespace std;

DynamicArray::DynamicArray(int n)
{
	this->innerArray = allocateMemory(n);
	this->capacity = n;
	this->length = 0;
}

DynamicArray::DynamicArray(const DynamicArray &array)
{
	this->allocateMemory(array.capacity);
	this->capacity = array.capacity;
	this->length = array.length;

	for (unsigned int i = 0; i < this->length; i++)
	{
		this->innerArray[i] = array.innerArray[i];
	}
}

DynamicArray::~DynamicArray()
{
	delete[] innerArray;
}

void DynamicArray::setLength(int n)
{
	if (n < 0)
	{
		throw invalid_argument("Length should be greater than 0");
	}

	this->length = n;
}

int DynamicArray::getLength() const
{
	return this->length;
}

int* DynamicArray::getArray() const
{
	return innerArray;
}

void DynamicArray::add(int item)
{
	int length = this->getLength();

	if (this->capacity - length <= 0)
	{
		this->capacity *= growthFactor;
		resizeMemory(innerArray, length, capacity);
	}

	this->innerArray[length] = item;
	setLength(length + 1);
}

int * DynamicArray::allocateMemory(int n)
{
	if (n < 0)
	{
		throw invalid_argument("Length should be greater than 0");
	}

	int *a = new int[n] { 0 };

	return a;
}

void DynamicArray::resizeMemory(int *& source , int sourceLength, int destinationLength)
{

	int *tmp = allocateMemory(destinationLength);

	copyArray(source, sourceLength, tmp);

	delete[] source;

	source = tmp;
}

void DynamicArray::copyArray(int *source, int n, int *destination) //можно усовершенствовать
{
	for (unsigned int i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
}
