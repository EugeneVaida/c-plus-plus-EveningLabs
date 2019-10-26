// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	double a;
	std::cout << "Input a: ";
	std::cin >> a;

	try {
		double z1 = (1 - 2 * pow(sin(a), 2)) / (1 + sin(2 * a));
		double z2 = (1 - tan(a)) / (1 + tan(a));
		std::cout << "\t" << z1 << "\t||\t" << z2 << "\t" << std::endl;
	}
	catch(int g){
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
