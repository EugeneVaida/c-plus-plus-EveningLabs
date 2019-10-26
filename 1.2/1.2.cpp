// 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>


int main()
{
	double x;
	std::cout << "Input x: ";
	std::cin >> x;

	double y;
	std::cout << "Input y: ";
	std::cin >> y;

	double z;
	std::cout << "Input z: ";
	std::cin >> z;

	try {
		double part1 = pow(y, pow(abs(x), 1 / 3.0));
		double part2 = pow(cos(y), 3);
		double part3 = abs(x - y) * (1 + (pow(sin(z), 2)/ sqrt(x + y)));
		double part4 = pow(M_E, abs(x - y)) + x/2;		
		double b = part1 + part2 * part3/part4;
		std::cout << "\t" << b << std::endl;
	}
	catch (int g) {
		std::cout << "Caught exception number:  " << g << std::endl;
	}

	std::cout << "No exception detected!" << std::endl;
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
