// 9.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

struct Stack {
	string c;
	Stack *Next = NULL;
};

int Prior(string);

Stack *InS(Stack *, string);

Stack *OutS(Stack *, string *);

int main() {
	Stack *t, *Op = NULL;
	string a, In, Out = "";
	int k = 0, l = 0;
	vector<string> variables;
	vector<double> values;
	puts("Input formula : ");
	getline(cin, In);
	string var_name = "";
	vector<string> op;
	while (In[k] != '\0') {
		if (In[k] >= 'a' && In[k] <= 'z') {
			var_name += In[k];
			Out += In[k];
			if (k == In.length() - 1) {
				if (find(variables.begin(), variables.end(), var_name) == variables.end()) {
					variables.push_back(var_name);
					op.push_back(var_name);
				}
				var_name = "";
				Out += " ";
			}
		}
		else if (var_name.length()) {
			if (find(variables.begin(), variables.end(), var_name) == variables.end()) {
				variables.push_back(var_name);
				op.push_back(var_name);
			}
			var_name = "";
			Out += " ";
		}
		if (In[k] == ')') {
			while ((Op->c) != "(") {
				Op = OutS(Op, &a);
				if (!Op) a = '\0';
				Out += a;
				op.push_back(a);
			}
			t = Op;
			Op = Op->Next;
			free(t);
		}

		if (In[k] == '(') Op = InS(Op, string(1, In[k]));
		if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/' || In[k] == '%' || In[k] == '^') {
			while (Op != NULL && Prior(Op->c) >= Prior(string(1, In[k]))) {
				Op = OutS(Op, &a);
				Out += a + " ";
				op.push_back(a);
			}
			Op = InS(Op, string(1, In[k]));
		}
		k++;
	}
	for (int i = 0; i < variables.size(); ++i) {
		cout << variables.at(i) << ":" << endl;
		double value;
		cin >> value;
		values.push_back(value);
	}
	vector<double> operations;
	while (Op != NULL) {
		Op = OutS(Op, &a);
		Out += a + " ";
		op.push_back(a);
	}

	while (!op.empty()) {
		string operation = op[0];
		op.erase(op.begin());
		if (operation[0] >= 'a' && operation[0] <= 'z') {
			operations.push_back(values[distance(variables.begin(), find(variables.begin(), variables.end(), operation))]);
		}
		else {
			double operand2 = operations[operations.size() - 1];
			operations.pop_back();
			double operand1 = operations[operations.size() - 1];
			operations.pop_back();
			double res;
			char a = operation[0];
			switch (a) {
			case '^':
				res = pow(operand1, operand2);
				break;
			case '*':
				res = operand1 * operand2;
				break;
			case '/':
				res = operand1 / operand2;
				break;
			case '%':
				res = fmod(operand1, operand2);
				break;
			case '-':
				res = operand1 - operand2;
				break;
			case '+':
				res = operand1 + operand2;
				break;
			}
			operations.push_back(res);
		}
	}
	cout << "\nPolish = " << Out << endl;
	cout << "Value = " << operations[0] << endl;
}

int Prior(string op) {
	if (op.length() == 1) {
		char a = op.at(0);
		switch (a) {
		case '^':
			return 4;
		case '*':
		case '/':
		case '%':
			return 3;
		case '-':
		case '+':
			return 2;
		case '(':
			return 1;
		}
	}
	return 0;
}

Stack *InS(Stack *t, string s) {
	Stack *t1 = new Stack;
	t1->c = s;
	t1->Next = t;
	return t1;
}

Stack *OutS(Stack *t, string *s) {
	Stack *t1 = t;
	*s = t->c;
	t = t->Next;
	delete (t1);
	return t;
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
