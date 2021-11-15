// DynamicMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FillRand.h"
#include "Print.h"
#include "Print.cpp"

using namespace std;


template<typename T>T* push_back(T arr[], int& size, T value);
template<typename T>T* push_front(T arr[], int& size, T value);
template<typename T>T* insert(T arr[], int& size, T value, int pos);
template<typename T>T* pop_back(T arr[], int& size);
template<typename T>T* pop_front(T arr[], int& size);
template<typename T>T* erase(T arr[], int& size, int pos);

template<typename T>T** allocate(int rows, int cols);
template<typename T>void clear(T** arr, int rows, int cols);
template<typename T>T** push_row_back(T** arr, int& rows, int cols);
template<typename T>T** push_row_front(T** arr, int& rows, int cols);


//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
#define PREFIRMANCE_CHECK

int main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cin >> n;
	int* arr = new int[n];
	full_rand(arr, n);
	Print(arr, n);
	arr = push_back(arr, n, 55);
	Print(arr, n);
	delete[]arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cin >> rows >> cols;
	int** arr = allocate(arr, rows, cols);
	full_rand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate<int>(rows, cols);
	full_rand(arr, rows, cols);
	Print(arr, rows, cols);
	clear(arr, rows, cols);
}





template<typename T>
T* push_back(T arr[], int& size, T value)
{
	T* copy = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		copy[i] = arr[i];
	}
	delete[]arr;
	arr = copy;
	copy[size] = value;
	size++;
	return arr;
}

template<typename T>
T* push_front(T arr[], int& size, T value)
{
	T* copy = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		copy[i + 1] = arr[i];
	}
	delete[]arr;
	arr = copy;
	copy[0] = value;
	size++;
	return arr;
}

template<typename T>
T* insert(T arr[], int& size, T value, int pos)
{
	T* copy = new T[size + 1];
	for (size_t i = 0; i < pos; i++)
	{
		copy[i] = arr[i];
	}
	copy[pos] = value;
	size++;
	for (size_t i = pos + 1; i < size; i++)
	{
		copy[i] = arr[i - 1];
	}
	delete[]arr;

	arr = copy;
	return arr;
}

template<typename T>
T* pop_back(T arr[], int& size)
{
	size--;
	T* copy = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		copy[i] = arr[i];
	}
	delete[]arr;
	arr = copy;
	return arr;
}

template<typename T>
T* pop_front(T arr[], int& size)
{
	int* copy = new int[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		copy[i] = arr[i + 1];
	}
	size--;
	delete[]arr;
	arr = copy;
	return arr;
}

template<typename T>
T* erase(T arr[], int& size, int pos)
{
	T* copy = new T[size];
	for (size_t i = 0; i < pos; i++)
	{
		copy[i] = arr[i];
	}
	for (size_t i = pos; i < size - 1; i++)
	{
		copy[i] = arr[i + 1];
	}
	size--;
	delete[]arr;
	arr = copy;
	return arr;
}

template<typename T>
T** allocate(int rows, int cols)
{
	T** arr = new T* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}

template<typename T>
void clear(T** arr, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

template<typename T>
T** push_row_back(T** arr, int& rows, int cols)
{
	T** copy = new T* [rows + 1];
	for (size_t i = 0; i < rows; i++)
	{
		copy[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
		{
			copy[i][j] = arr[i][j];
		}
	}
	for (size_t i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	copy[rows] = new T[cols] {};
	rows++;
	arr = copy;
	return copy;
}

template<typename T>
T** push_row_front(T** arr, int& rows, int cols)
{
	T** copy = new T* [rows + 1];
	for (size_t i = 0; i < rows; i++)
	{
		copy[i] = new T[cols];
		for (size_t j = 0; j < cols; j++)
		{
			copy[i + 1][j] = arr[i][j];
		}
	}
	for (size_t i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	copy[0] = new T[cols] {};
	rows++;
	arr = copy;
	return copy;
}

int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [--rows];
	for (size_t i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr[rows];
	delete[]arr;
	return buffer;
}

template<typename T>
void push_col_back(T** arr, int rows, int& cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		T* copy = new T[cols+1] {};
		for (size_t j = 0; j < cols; j++)
		{
			copy[j] = arr[i][j];
		}
		delete[]arr[i];
		arr[i] = copy;
	}
	cols++;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
