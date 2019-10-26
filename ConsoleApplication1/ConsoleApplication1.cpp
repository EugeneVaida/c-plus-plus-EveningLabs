// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int min(int x, int y)
{
	return (x <= y) ? (x) : (y);
}

int max(int x, int y) 
{
	return (x <= y) ? (y) : (x);
}

int sqr(int x) 
{
	return x * x;
}

int main()
{
	int x;
	int y;
	double t;
	std::cout << "Input x: ";
	std::cin >> x;
	std::cout << "Input y: ";
	std::cin >> y;

	int result = sqr(max(max(x * y, x + y), 0));

	std::cout << "Your x: " << x << "\t your y: " << y << "\t result:" << result << std::endl;
	return 0;
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
