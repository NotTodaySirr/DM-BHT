#include "DataGenerator.h"
using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh m?ng d? li?u ng?u nhiên
void GenerateRandomData(int* a, int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh m?ng d? li?u có th? t? t?ng d?n
void GenerateSortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh m?ng d? li?u có th? t? ng??c (gi?m d?n)
void GenerateReverseData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh m?ng d? li?u g?n nh? có th? t?
void GenerateNearlySortedData(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int* &a, int n, const string datatype)
{
	//random order
	if (datatype == "-rand") GenerateRandomData(a, n);

	//sorted order
	else if(datatype == "-sorted") GenerateSortedData(a, n);

	//reverse order
	else if (datatype == "-rev") GenerateReverseData(a, n);

	//nearly sorted order
	else if (datatype == "-nsorted") GenerateNearlySortedData(a, n);

	else cout << "Invalid data type" << endl;	
}