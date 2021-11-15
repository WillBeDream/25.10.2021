#include "FillRand.h"


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