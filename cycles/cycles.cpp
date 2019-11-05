// cycles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	double a;
	double b;
	double h;
	double x = 0;
	double min = 0;
	double max = 0;
	double result;
	double tempResult;
	std::cout << "Input a: ";
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;
	std::cout << "Input h: ";
	std::cin >> h;

	int counter = 1;
	string isRise = "";
	for (a; a <= b; a++) {		
		result = pow(x, 2)*cos(x)*sin(x);	
				
		if (min == 0) {
			min = result;
		}
		else if (result < min) {
			min = result;
		}
				
		if (max == 0) {
			max = result;
		}
		else if (result > max) {
			max = result;
		}

		if (counter >= 2) {
			if ((x) > (x - h) && (result > tempResult)) {
				isRise = "increase!";
			}
			else {
				isRise = "decrease!";
			}
		}
			
		cout << counter << "." << "Your x: " << x << "\t result:" << result << "  " << isRise << endl;
		x = x + h;
		
		counter++;
		tempResult = result;
	}

	cout << " Min result: " << min << "\t Max result:" << max << endl;
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
