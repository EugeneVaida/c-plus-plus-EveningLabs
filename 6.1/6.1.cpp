// 6.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>

struct Student
{
	int birthdyYear;
	int groupNumber;
	std::string surname;
	int markphisics;
	int markmath;
	int markchemostry;
	int markinformatic;
	double average;
};

void OutputStudent(Student student);
void CreateStudentsList(Student* spisok, int* counter);

void PrintStudentsAboveAverageInGroup(Student* spisok, int* counter, int group);
double FindStudentsAverageMark(Student* spisok, int* counter);



int main()
{
	Student spisok[100];
	int counter = 0;
	CreateStudentsList(spisok, &counter);

	PrintStudentsAboveAverageInGroup(spisok, &counter, 10);
}

void CreateStudentsList(Student* spisok, int* counter)
{
	Student newStudent1;
	newStudent1.surname = "Dilan B.";
	newStudent1.birthdyYear = 2001;
	newStudent1.groupNumber = 10;
	newStudent1.markmath = 9;
	newStudent1.markinformatic = 8;
	newStudent1.markphisics = 7;
	newStudent1.markchemostry = 6;
	newStudent1.average = (double)(newStudent1.markmath + newStudent1.markinformatic + newStudent1.markphisics + newStudent1.markchemostry) / 4;
	spisok[*counter] = newStudent1;
	*counter = *counter + 1;

	Student newStudent2;
	newStudent2.surname = "Totword R.";
	newStudent2.birthdyYear = 2000;
	newStudent2.groupNumber = 10;
	newStudent2.markmath = 6;
	newStudent2.markinformatic = 8;
	newStudent2.markphisics = 7;
	newStudent2.markchemostry = 4;
	newStudent2.average = (double)(newStudent2.markmath + newStudent2.markinformatic + newStudent2.markphisics + newStudent2.markchemostry) / 4;
	spisok[*counter] = newStudent2;
	*counter = *counter + 1;

	Student newStudent3;
	newStudent3.surname = "Richardson F.";
	newStudent3.birthdyYear = 2000;
	newStudent3.groupNumber = 11;
	newStudent3.markmath = 6;
	newStudent3.markinformatic = 1;
	newStudent3.markphisics = 7;
	newStudent3.markchemostry = 4;
	newStudent3.average = (double)(newStudent3.markmath + newStudent3.markinformatic + newStudent3.markphisics + newStudent3.markchemostry) / 4;
	spisok[*counter] = newStudent3;
	*counter = *counter + 1;

	Student newStudent4;
	newStudent4.surname = "Youth T.";
	newStudent4.birthdyYear = 2000;
	newStudent4.groupNumber = 10;
	newStudent4.markmath = 10;
	newStudent4.markinformatic = 10;
	newStudent4.markphisics = 10;
	newStudent4.markchemostry = 10;
	newStudent4.average = (double)(newStudent4.markmath + newStudent4.markinformatic + newStudent4.markphisics + newStudent4.markchemostry) / 4;
	spisok[*counter] = newStudent4;
	*counter = *counter + 1;

	Student newStudent5;
	newStudent5.surname = "Youth M.";
	newStudent5.birthdyYear = 2000;
	newStudent5.groupNumber = 15;
	newStudent5.markmath = 10;
	newStudent5.markinformatic = 10;
	newStudent5.markphisics = 6;
	newStudent5.markchemostry = 10;
	newStudent5.average = (double)(newStudent5.markmath + newStudent5.markinformatic + newStudent5.markphisics + newStudent5.markchemostry) / 4;
	spisok[*counter] = newStudent5;
	*counter = *counter + 1;
}

double FindStudentsAverageMark(Student* spisok, int* counter)
{
	double studentsAverageSum = 0;
	for (int i = 0; i < *counter; i++)
	{		
		studentsAverageSum += spisok[i].average;
	}
	return studentsAverageSum / *counter;
}

void PrintStudentsAboveAverageInGroup(Student* spisok, int* counter, int group)
{
	double averageMark = FindStudentsAverageMark(spisok, counter);
	std::cout << "Students average mark: ";
	std::cout << averageMark;
	std::cout << '\n';
	std::cout << '\n';
	
	for (int i = 0; i < *counter; i++)
	{
		if (spisok[i].average >= averageMark && spisok[i].groupNumber == group)
		{
			OutputStudent(spisok[i]);
			std::cout << '\n';
		}
	}	
}

void OutputStudent(Student student)
{
	std::cout << '\n';
	std::cout << "Surname: ";
	std::cout << student.surname;
	std::cout << '\n';
	std::cout << "Group N.: ";
	std::cout << student.groupNumber;
	std::cout << '\n';
	std::cout << "Average mark: ";	
	std::cout << student.average;
	std::cout << '\n';
	std::cout << "Birthday Year: ";
	std::cout << student.birthdyYear;
}

