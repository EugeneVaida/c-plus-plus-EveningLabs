#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>


struct Stack {
	int value;
	Stack* Next;
};

Stack* Create(Stack* begin);
void View(Stack* begin);
Stack* Add(Stack* begin, int i);
Stack* CreateFrequencyStack(Stack* begin);
int CountFrequencyOfElement(Stack* begin, int element);
int GetLimitsInStack(Stack* begin, int type);
int FindMaxInStac(Stack* begin);
Stack* RemoveElements(Stack* begin, Stack* data, int index);
Stack* FlipStack(Stack* begin);
Stack* CreateTen();
Stack* deleteRange(Stack* begin, int min, int max);
void PrintElementsInStack(Stack* begin);

int main()
{
	Stack* begin = CreateTen();
	PrintElementsInStack(begin);
	Stack* data = NULL;
	int repeat = 1;
	int counter = 10; //set 0 if y want manual 
	int max = GetLimitsInStack(begin, 2);
	int min = GetLimitsInStack(begin, 1);

	Stack* cleanedStack = deleteRange(begin, min, max);	
	Stack* flipedStack = FlipStack(cleanedStack);
	PrintElementsInStack(flipedStack);	
}

Stack* Create(Stack* begin)
{
	Stack* t = (Stack*)malloc(sizeof(Stack));
	std::cout << ("\n Input Info  ");
	std::cin >> t->value;
	t->Next = begin;
	return t;
}

Stack* Add(Stack* begin, int i)
{
	Stack* t = (Stack*)malloc(sizeof(Stack));
	t->value = i;
	t->Next = begin;
	return t;
}

void View(Stack* begin)
{
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return;
	}
	while (t != NULL) {
		std::cout << '\n';
		std::cout << (t->value);
		t = t->Next;
	}
}

int CountFrequencyOfElement(Stack* begin, int element)
{
	int count = 0;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return count;
	}
	while (t != NULL) {
		if (t->value == element)
		{
			count++;
		}
		t = t->Next;
	}
	return count;
}

// types: 1 - low; 2 - high
int GetLimitsInStack(Stack* begin, int type)
{
	int limit = 0;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return limit;
	}
	if (type == 1) {
		limit = t->value;
	}
	while (t != NULL) {
		if (type == 1 ? (t->value < limit) : (t->value > limit))
		{
			limit = t->value;
		}
		t = t->Next;
	}
	return limit;
}


int FindMaxInStac(Stack* begin)
{
	int max = -1;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return max;
	}
	else
	{
		max = t->value;
	}
	while (t != NULL) {
		if (t->value > max)
		{
			max = t->value;
		}
		t = t->Next;
	}
	return max;
}

Stack* CreateFrequencyStack(Stack* begin)
{
	Stack* out = NULL;
	int count = 0;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return out;
	}
	while (t != NULL)
	{
		int count = CountFrequencyOfElement(begin, t->value);
		out = Add(out, count);
		t = t->Next;
	}
	return out;
}

Stack* deleteRange(Stack* begin, int min, int max)
{
	Stack* out = NULL;
	int count = 0;
	bool rangeStart = false;
	bool once = false;
	int start = 0;
	int end = 0;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return out;
	}
	while (t != NULL)
	{
		if ((t->value == min || t->value == max) && !rangeStart && !once) {
			if (t->value == min) {
				start = min;
				end = max;
			}
			else if (t->value == max) {
				start = max;
				end = min;
			}
			rangeStart = true;
			out = Add(out, t->value);
		}
		else if (t->value == end) {
			rangeStart = false;		
			once = true;
			out = Add(out, t->value);
		}else if(!rangeStart){
			out = Add(out, t->value);			
		}else if (rangeStart) {
			count++;
		}
		t = t->Next;
	}
	std::cout << count << " Elements deleted." << "\n";
	std::cout << "Range:" << start << "..."<< end <<"\n";
	return out;
}

Stack* FlipStack(Stack* begin)
{
	Stack* out = NULL;
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");
		return out;
	}
	while (t != NULL)
	{		
		out = Add(out, t->value);		
		t = t->Next;
	}
	return out;
}


void PrintElementsInStack(Stack* begin)
{
	Stack* t = begin;
	if (begin == NULL) {
		std::cout << ("Stac empty");		
	}
	while (t != NULL) {
		std::cout << t->value << " ";
		t = t->Next;
	}
	std::cout << '\n';
}


Stack* CreateTen()
{
	Stack* out = NULL;
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 30 + 1;
		out = Add(out, random);
	}
	return out;
}