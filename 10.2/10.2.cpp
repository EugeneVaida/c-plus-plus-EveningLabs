// 10.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iostream>
#include <string>


template <size_t size_x, size_t size_y>
int func(int(&arr)[size_x][size_y], int length = 5);

template <size_t size_x, size_t size_y>
void show(int(&arr)[size_x][size_y], int length = 5);

using namespace std;
int main()
{

	int TDarray[5][5] =
	{
		{2, 0, -7, -1, 2},
		{2, 4, 5, 1, 2},
		{-2, 4, 5, -4, 2},
		{2, -8, 5, 1, 0},
		{2, 4, -5, 1, 9},
	};
	show(TDarray);
	int p = func(TDarray);

	std::cout << p;
}

template <size_t size_x, size_t size_y>
int func(int(&arr)[size_x][size_y], int length)
{	
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			int t = arr[i][j];
			if (abs(t) % 2 == 1 && t < 0)
			{
				sum += abs(t);
			}
		}
	}
	return sum;
}

template <size_t size_x, size_t size_y>
void show(int(&arr)[size_x][size_y], int length)
{
	bool flag = false;
	int sum = 0;
	int minimum = arr[0][0];
	int column = -1;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			int t = arr[i][j];
			cout << t << " ";
		}
		cout << endl;
	}
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
