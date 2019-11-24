// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	
	int n = 11;
	int sum = 0;
	
	while (n > 10) {
		std::cout << "How many item will be in your array?: ";
		std::cin >> n;
	}
	// Заполняем массив с клавиатуры
	int* linkToArray = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]" << ": ";
		cin >> linkToArray[i];
	}
	for (int i = 0; i < n; i++) {
		
		if (linkToArray[i] == 0) {
			sum = 0;
		}
		else {
			sum += linkToArray[i];
		}		
	}
	cout << "Sum after the last 0 element: " << sum << endl;
	delete[] linkToArray;
    
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
