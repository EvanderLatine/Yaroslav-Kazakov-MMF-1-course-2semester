#include <fstream>
#include <iostream>
#include <cstdlib> 

const int N = 5;

using namespace std;

void inputDimensions(int& n, int& m);
double** generateMatrice(int, int);
double* generateArray(int);
double* matrixMultiplication(double**, double*, int, int);
void displayMatrix(double**, int, int);
void displayArray(double*, int);
void sourceFile(char*, double**, double*, int, int);
void resultFile(char*, double*, int);

int main()
{
	const int N = 3;

	char sourcePass[33] = "C:\\Users\\ASUS\\Desktop\\Source.bin";
	char resultPass[33] = "C:\\Users\\ASUS\\Desktop\\Result.bin";
	int raws, columns;

	inputDimensions(raws, columns);
	
	double** resultsArray = new double* [N];

	for (int i = 0; i < N; i++)
	{
		double** n_m = generateMatrice(raws, columns);
		double* m_1 = generateArray(columns);
		resultsArray[i] = matrixMultiplication(n_m, m_1, raws, columns);

		cout << i + 1 << " matrices:" << endl;
		displayMatrix(n_m, raws, columns);
		displayArray(m_1, columns);

		sourceFile(sourcePass, n_m, m_1, raws, columns);
	}

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		cout << " result " << i + 1 << ":" << endl;

		displayArray(resultsArray[i], columns);

		resultFile(resultPass, resultsArray[i], columns);
	}
}

void inputDimensions(int& n, int& m)
{
	cout << "Ammount of matrix rows:\n";
	cin >> n;
	system("cls");
	cout << "Ammount of matrix coloumns:\n";
	cin >> m;
	system("cls");
}

double** generateMatrice(int n, int m)
{
	double** matrix = new double* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];

		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = 0.01 * (rand() % 101);
		}
	}

	return matrix;
}

double* generateArray(int n)
{
	double* matrix = new double [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = 0.01 * (rand() % 101);
	}

	return matrix;
}

double* matrixMultiplication(double** n_m, double* m_1, int n, int m)
{
	double temp = 0;

	double* result = new double[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp += n_m[i][j] * m_1[j];
		}

		result[i] = temp;
	}

	return result;
}

void displayMatrix(double** matrix, int n, int m)
{
	for ( int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << '\n';
	}
	cout << endl;
}

void displayArray(double* m_1, int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << m_1[i] << "\t";
	}
	cout << endl;
}

void sourceFile(char* fileName, double** n_m, double* m_1, int n, int m)
{
	ofstream streamOut;

	streamOut.open(fileName, ios::binary);

	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		return;
	}

	int n_mSize = sizeof(double) * n * m;
	int m_1Size = sizeof(double) * m;
	
	streamOut.write((char*)& n_m, n_mSize);
	streamOut.write((char*)& m_1, m_1Size);

	streamOut.close();
}

void resultFile(char* fileName, double* result, int m)
{
	ofstream streamOut;

	streamOut.open(fileName, ios::binary);

	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		return;
	}

	int resultSize = sizeof(double) * m;

	streamOut.write((char*)& result, resultSize);

	streamOut.close();
}