// 8.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>


struct list
{
	int value; // поле данных
	struct list* next; // указатель на следующий элемент
	struct list* prev; // указатель на предыдущий элемент
};

void View(list* begin);
list* CreateTen();
list* Add(list* begin, int i);
list* init(int a);
list* DeleteElem(list* lst);
list* MakeTask(list* lst, int average);
int FindMax(list* lst);
void ViewN(list* lst);
list* Flip(list* begin);
void printList(list* lst);

int main()
{
	list* begin = CreateTen();
	std::cout << '\n';
	printList(begin);
	list* cleaned = MakeTask(begin, FindMax(begin));	
	printList(cleaned);
}

list* CreateTen()
{
	list* out = NULL;
	srand(time(NULL));


	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 30 + 1;
		if (out == NULL)
		{
			out = init(random);
		}
		else
		{
			out = Add(out, random);
		}
	}
	return out;
}


list* init(int a)
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->value = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	return(lst);
}

list* Add(list* lst, int number)
{
	struct list* temp, *p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->value = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

void View(list* lst)
{
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		std::cout << '\n';
		std::cout << (p->value);
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
}

void ViewN(list* lst)
{
	struct list* p;
	p = lst;
	do {
		std::cout << '\n';
		std::cout << (p->value);
		p = p->next; // переход к следующему узлу
	} while (p != NULL); // условие окончания обхода
}

struct list* DeleteElem(list* lst)
{
	struct list* prev, *next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	if (prev != NULL)
		prev->next = lst->next; // переставляем указатель
	if (next != NULL)
		next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
}

list* MakeTask(list* lst, int max)
{	
	bool deletionActivation = false;
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		if (p->value == max && !deletionActivation)
		{
			deletionActivation = true;					
		}else if (deletionActivation) {
			p->prev = DeleteElem(p);
		}
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
	return lst;
}

int FindMax(list* lst)
{
	int average = 0;
	int max = 0;
	int count = 0;
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		if (count == 0) {
			max = p->value;
		}
		else {
			if (p->value > max) {
				max = p->value;
			}
		}
		p = p->prev; // переход к предыдущему узлу
		count++;
	} while (p != NULL); // условие окончания обхода
	return max;
}

list* Flip(list* lst)
{
	list* out = NULL;
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		if (out == NULL)
		{
			out = init(p->value);
		}
		else
		{
			out = Add(out, p->value);
		}
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
	return out;
}

void printList(list* lst)
{
	struct list* p;
	p = lst;
	while (p->next != NULL)
		p = p->next;  // переход к концу списка
	do {
		std::cout << p->value << " ";
		p = p->prev; // переход к предыдущему узлу
	} while (p != NULL); // условие окончания обхода
	std::cout << "\n";
}