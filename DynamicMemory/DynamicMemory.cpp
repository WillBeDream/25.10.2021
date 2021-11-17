// DynamicMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void full_rand(int arr[], int size);
void full_rand(int** arr, int rows, int cols);

void Print(int arr[], int size);
void Print(int** arr, int rows, int cols);

int* push_back(int arr[], int& size, int value);
int* push_front(int arr[], int& size, int value);
int* insert(int arr[], int& size, int value, int pos);
int* pop_back(int arr[], int& size);
int* pop_front(int arr[], int& size);
int* erase(int arr[], int& size, int pos);

int** allocate(int rows, int cols);
void clear(int** arr, int rows, int cols);
int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);


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
	int** arr = allocate(rows, cols);
	cout << "Память выделена, для добавления строки в конец массива нажмите любую клавишу;\n";
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	cout << "Строка добавлена.\n";
	clear(arr, rows, cols);

}

void full_rand(int arr[], int size)
{
	srand(time(0));
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void full_rand(int** arr, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Print(int** arr, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int* push_back(int arr[], int& size, int value)
{
	int* copy = new int[size + 1];
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

int* push_front(int arr[], int& size, int value)
{
	int* copy = new int[size + 1];
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

int* insert(int arr[], int& size, int value, int pos)
{
	int* copy = new int[size + 1];
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
int* pop_back(int arr[], int& size)
{
	size--;
	int* copy = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		copy[i] = arr[i];
	}
	delete[]arr;
	arr = copy;
	return arr;
}

int* pop_front(int arr[], int& size)
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

int* erase(int arr[], int& size, int pos)
{
	int* copy = new int[size];
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

int** allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void clear(int** arr, int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}

int** push_row_back(int** arr, int& rows, int cols)
{
	int** copy = new int* [rows + 1];
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
	copy[rows] = new int[cols] {};
	rows++;
	arr = copy;
	return copy;
}

int** push_row_front(int** arr, int& rows, int cols)
{
	int** copy = new int* [rows + 1];
	for (size_t i = 0; i < rows; i++)
	{
		copy[i] = new int[cols];
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
	copy[0] = new int[cols] {};
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

void push_col_back(int** arr, int rows, int& cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		int* copy = new int[cols+1] {};
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
