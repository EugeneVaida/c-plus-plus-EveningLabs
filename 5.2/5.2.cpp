// 5.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <math.h>
#include <iostream>

double Rec(int i, int n);
double NoRec(int n);

int main()
{
	int numb = 0;
	std::cout << "enter number";
	std::cout << '\n';
	std::cin >> numb;
	std::cout << '\n';
	std::cout << "with  recursion";
	std::cout << '\n';
	std::cout << Rec(1, numb);
	std::cout << '\n';
	std::cout << "without  recursion";
	std::cout << '\n';
	std::cout << NoRec(numb);
}

double Rec(int i, int n)
{	
	if (n > i)
	{
		return sqrt(i + Rec(i + 1, n));
	}
	return sqrt(n);
}

double NoRec(int n) {
	double result = sqrt(n);
	while (n > 1) {
		result = sqrt(n - 1 + result);
		n--;
	}
	return result;
}

