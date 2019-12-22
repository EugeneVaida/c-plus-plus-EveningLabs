#include "pch.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

struct Student
{
	string surname;
	int birthdyYear;	
	double average;
	int groupNumber;
};

string ConvertToString(Student* spisok, int* counter);
void ConvertToList(Student* spisok, int* counter);

vector<Student> MakeDataSetVector();
string ConvertToStringVector(vector<Student> spisok);
vector<Student>  ConvertToListVector();
vector<Student> Edit(vector<Student> spisok, int numb);
vector<Student> Delete(vector<Student> spisok, int numb);
vector<Student> Add(vector<Student> spisok);

double FindStudentsAverageMark(vector<Student> spisok);
void PrintStudentsAboveAverageInGroup(vector<Student> spisok, int group);
void OutputStudent(Student student);

Student CreateStudent();

//Написать программу по обработке файла, состоящего из структур, со - 
//держащих информацию задания 6. Средний балл рассчитать программно по введенным 
//оценкам.Массив структур не использовать.
//В программе реализовать следующие действия по обработке файла :
//– создание;
//– просмотр;
//– добавление нового элемента;
//– удаление(редактирование);
//– решение индивидуального задания(первый уровень сложности  зада - ния 6).
//Результаты выполнения индивидуального задания записать в текстовый файл.


int main()
{
	ofstream outfile("test.txt");

	vector<Student> v = MakeDataSetVector();
	//v = ConvertToListVector();

	string ss = ConvertToStringVector(v);
	cout << "******* base students list ************";
	cout << '\n';
	cout << ss;
	outfile << ss;
	outfile.close();
	cout << '\n';
	cout << "***************************************";
	v = ConvertToListVector();
	int number = -1;
	cout << '\n';
	cout << "select number of record to edit ";
	cin >> number;
	cout << '\n';

	cout << '\n';
	cout << "Editing " << number << " record " ;
	cout << '\n';

	v = Edit(v, number - 1);
	cout << '\n';

	ofstream outfile1("test.txt");
	string ss1 = ConvertToStringVector(v);
	outfile1 << ss1;
	outfile1.close();

	cout << '\n';
	cout << "List after editing";
	cout << '\n';
	cout << ss1;


	cout << '\n';
	cout << "select number of record to delete ";
	cin >> number;
	cout << '\n';

	cout << '\n';
	cout << "Deleting " << number << " record";
	cout << '\n';

	v = Delete(v, number);
	cout << '\n';

	ofstream outfile2("test.txt");
	string ss2 = ConvertToStringVector(v);
	outfile2 << ss2;
	outfile2.close();

	cout << '\n';
	cout << "List after deleting " << number;
	cout << '\n';
	cout << ss2;
	
	
	cout << "Add new ";
	v = Add(v);
	cout << '\n';

	ofstream outfile3("test.txt");
	string ss3 = ConvertToStringVector(v);
	outfile3 << ss3;
	outfile3.close();

	cout << '\n';
	cout << "List after add new student";
	cout << '\n';
	cout << ss3;

	cout << '\n';
	PrintStudentsAboveAverageInGroup(v, 10);

	return 0;
}

vector<Student> Edit(vector<Student> spisok, int numb)
{
	vector<Student> spis;
	Student newStudent = CreateStudent();

	int counter = 0;
	for (Student n : spisok)
	{
		if (counter == numb)
		{
			spis.push_back(newStudent);
		}
		else
		{
			spis.push_back(n);
		}
		counter++;
	}
	return spis;

}

Student CreateStudent() {
	Student newStudent;
	string surname = "";
	int average = 0;
	int birdhday = 0;
	int group = 0;
	cout << '\n';
	cout << "Enter Surname: ";
	cin >> surname;
	newStudent.surname = surname;
	cout << '\n';
	cout << "Enter average: ";
	cin >> average;
	newStudent.average = average;
	cout << '\n';
	cout << "Enter birdthday: ";
	cin >> birdhday;
	newStudent.birthdyYear = birdhday;
	cout << '\n';
	cout << "Enter group: ";
	cin >> group;
	newStudent.groupNumber = group;

	return newStudent;
}

vector<Student> Add(vector<Student> spisok)
{
	Student newStudent = CreateStudent();		
	spisok.push_back(newStudent);
		
	return spisok;
}

double FindStudentsAverageMark(vector<Student> spisok)
{
	double studentsAverageSum = 0;
	for (Student n : spisok)
	{
		studentsAverageSum += n.average;
	}
	return studentsAverageSum / spisok.size();
}

void PrintStudentsAboveAverageInGroup(vector<Student> spisok, int group)
{
	double averageMark = FindStudentsAverageMark(spisok);
	std::cout << "Students average mark: ";
	std::cout << averageMark;
	std::cout << '\n';
	std::cout << '\n';

	ofstream outfile3("test.txt", ios::app);
	std::string ss3 = "Average mark: " + std::to_string(averageMark);
	outfile3 << ss3;
	outfile3.close();

	for (Student n : spisok)
	{
		if (n.average >= averageMark && n.groupNumber == group)
		{
			OutputStudent(n);
			std::cout << '\n';
		}
	}
}

vector<Student> Delete(vector<Student> spisok, int numb)
{
	spisok.erase(spisok.begin() + numb - 1);	
	return spisok;
}

string ConvertToStringVector(vector<Student> spisok)
{
	string outstr = "";
	for (Student n : spisok) {
		outstr += n.surname;
		outstr += '\n';
		outstr += to_string(n.average);
		outstr += '\n';
		outstr += to_string(n.birthdyYear);
		outstr += '\n';
		outstr += '\n';
	}
	return outstr;
}

void OutputStudent(Student student) {
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



vector<Student> ConvertToListVector()
{
	vector<Student> v;
	int counter = 0;
	string line;
	ifstream infile("test.txt");
	if (infile.is_open())
	{
		Student newStudent;
		while (getline(infile, line))
		{
			if (counter == 0)
			{				
				newStudent.surname = line;
			}
			if (counter == 1)
			{
				newStudent.average = stoi(line);				
			}
			if (counter == 2)
			{
				newStudent.birthdyYear = stoi(line);
			}
			if (line == "")
			{
				counter = -1;
				v.push_back(newStudent);
			}
			counter++;
		}
		infile.close();
	}
	return v;
}

string ConvertToString(Student* spisok, int* counter)
{
	string outstr = "";
	for (int i = 0; i < *counter - 1; i++)
	{
		outstr += spisok[i].surname;
		outstr += '\n';
		outstr += to_string(spisok[i].average);
		outstr += '\n';
		outstr += to_string(spisok[i].birthdyYear);
		outstr += '\n';
	}
	return outstr;
}
void ConvertToList(Student* spisok, int* counter)
{
	string line;
	ifstream infile("test.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			Student newStudent;

			cout << line << '\n';
		}
		infile.close();
	}
}

vector<Student> MakeDataSetVector()
{
	vector<Student> out;

	Student newStudent1;
	newStudent1.surname = "Mark";
	newStudent1.birthdyYear = 2001;
	newStudent1.average = 7;
	newStudent1.groupNumber = 10;
	out.push_back(newStudent1);

	Student newStudent2;
	newStudent2.surname = "Dilan";
	newStudent2.birthdyYear = 2000;
	newStudent2.average = 5;
	newStudent2.groupNumber = 10;
	out.push_back(newStudent2);

	Student newStudent3;
	newStudent3.surname = "Roy";
	newStudent3.birthdyYear = 2002;
	newStudent3.average = 3;
	newStudent3.groupNumber = 8;
	out.push_back(newStudent3);

	Student newStudent4;
	newStudent4.surname = "Tracy";
	newStudent4.birthdyYear = 2000;
	newStudent4.average = 10;
	newStudent4.groupNumber = 8;
	out.push_back(newStudent4);

	return out;
}