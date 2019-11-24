// cyclesStage2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <math.h>
#include <iostream>


float FX(float x);
void PrintResult(double a, double b, double s, int n);
bool CompareDoubles(double number1, double number2);
double NormalizeDouble(const double val, const int digits);

int main()
{
	float x;
	double a = 0.1;
	double b = 1;
	double h = 0.1;
	double n = 10;

	PrintResult(a, b, h, n);
}

float FX(float x) {

	return ((1 + pow(x, 2))/2) * atan(x) - x/2;
}

float SX(float x, int n) {
	float result;
	float sum = 0;
	for (int i = 1; i < n; i++) {
		result = pow(-1, i + 1) * (pow(x, 2 * i + 1) / (4 * pow(i, 2) - 1));
		sum = sum + result;
	}
	return sum;
}

void PrintResult(double a, double b, double s, int n) {

	int numb = 0;
	while (!CompareDoubles(a, b)) {
		float answ = FX(a);
		float answ2 = SX(a, n);
		a = a + s;
		numb++;

		std::cout << '\n';
		std::cout << numb;
		std::cout << "   ";
		std::cout << answ;
		std::cout << "   ";
		std::cout << answ2;
	}
}
bool CompareDoubles(double number1, double number2){

	if (NormalizeDouble(number1 - number2, 8) == 0)
		return(true);
	else
		return(false);
}
double NormalizeDouble(const double val, const int digits) {
	double power = pow(10, digits);
	return floor((val * power) + 0.5) / power;
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
