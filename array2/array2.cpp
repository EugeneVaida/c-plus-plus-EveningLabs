// array2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int m = 0;
	int sum = 0;

	while (n <= 0) {
		cout << "How many columns will be in your array?: ";
		cin >> n;		
	}

	while (m <= 0) {
		cout << "How many rows will be in your array?: ";
		cin >> m;
	}

	// Заполняем массив с клавиатуры
	int** linkToArray = new int*[m];
	for (int i = 0; i < m; ++i)
		linkToArray[i] = new int[n];
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ": ";
			cin >> linkToArray[i][j];
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cout << linkToArray[i][j] << endl;
		}
	} 

	if (n == m) {
		cout << "Square matrix!" << endl;

		for (int col = 0; col < m; col++) {
			for (int row = 0; row < n; row++) {
				if (row < col) {
					sum += linkToArray[col][row];
				}
			}
		}

		cout << "Sum of the elements below the main diagonal: " << sum << endl;
	}
	else {
		cout << "Matrix is not square!" << endl;
	}
	
	
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
