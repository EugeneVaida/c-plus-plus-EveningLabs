// cyclesStage2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int a;
	int b;
	int h;
	int x;

	double sum = 0;

	std::cout << "Array length: ";
	std::cin >> a;

	double funcResult;
	std::cout << "Input a: ";
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;
	std::cout << "Input h: ";
	std::cin >> h;

	std::cout << "Input x: ";
	std::cin >> x;
	std::cout << "\tfun   \t||\t  sum \t" << std::endl;
	for (a; a <= b; a++) 
	{
		funcResult = (1 + pow(x, 2)/2)*atan(x)-x/2;
		sum += pow(-1, a + 1)*pow(x, 2 * a + 1) / 4 * pow(a, 2);
		std::cout << "\t" << sum << "\t||\t" << funcResult << "\t" << std::endl;
		x = x + h;
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
