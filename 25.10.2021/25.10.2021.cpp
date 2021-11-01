// 25.10.2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define POINTERS_BASICS
#define POINTERS_AND_ARRAYS

int main()
{
    setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
    /*int a = 2;
    int* pa = &a;
    cout << a << endl;
    cout << &a << endl;
    cout << *pa;*/
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
    const int n = 5;
    int arr[n] = { 3,5,8,13,21 };
    cout << *arr << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << *(arr + i) << endl;
    }
#endif // 


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
