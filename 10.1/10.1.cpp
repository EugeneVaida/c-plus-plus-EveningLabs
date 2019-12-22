// 10.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


int ArrayMoreT(int inArray[], int length = 10);

int ArrayMoreT(double inArray[], int length = 10);

template <typename T>
void printArray(const T* array, int count = 10);

int main()
{
	cout << "Enter int array" << endl;
	int* array1I = new int[10];
	for (int i = 0; i < 10; ++i) {
		cin >> array1I[i];
	}
	cout << endl << "Count of numbers less than 0: " << ArrayMoreT(array1I) << endl;

	cout << "Enter double array" << endl;
	double* array2D = new double[10];
	for (int i = 0; i < 10; ++i) {
		cin >> array2D[i];
	}
	cout << endl << "Count of numbers less than 0: " << ArrayMoreT(array2D) << endl;
	cout << "Printing array with the most count of negative elements..." << endl;
	if (ArrayMoreT(array1I) <= ArrayMoreT(array2D))
	{
		printArray(array2D);
	}
	else
	{
		printArray(array1I);
	}
}

int ArrayMoreT(int inArray[], int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (inArray[i] < 0)
		{
			count++;
		}
	}
	return count;
}

int ArrayMoreT(double inArray[], int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (inArray[i] < 0)
		{
			count++;
		}
	}
	return count;
}

template <typename T>
void printArray(const T* array, int count)
{
	for (int ix = 0; ix < count; ix++)
		cout << array[ix] << "   ";
	cout << endl;
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
