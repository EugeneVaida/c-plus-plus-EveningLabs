// cycles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

int main()
{
	int a;
	int b;
	int h;
	int x;
	double result;
	std::cout << "Input a: ";
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;
	std::cout << "Input h: ";
	std::cin >> h;

	std::cout << "Input x: ";
	std::cin >> x;

	for (a; a <= b; a++) {		
		result = pow(x, 2)*cos(x)*sin(x);	
		std::cout << "Your x: " << x << "\t result:" << result << std::endl;
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
