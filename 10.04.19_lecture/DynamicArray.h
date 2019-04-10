#pragma once
class DynamicArray
{
public:
	DynamicArray() : DynamicArray(defaultCapacity) { capacity = 4; }
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();

	void setLength(int);
	int getLength() const;
	int* getArray() const; //dab code !!!!!!!!!!!!

	void add(int);

private:
	const int defaultCapacity = 4;
	const int growthFactor = 2;
	int *innerArray;
	int length;
	int capacity;
	static int* allocateMemory(int);
	static void resizeMemory(int*&, int, int);

	static void copyArray(int*, int, int*);
};

