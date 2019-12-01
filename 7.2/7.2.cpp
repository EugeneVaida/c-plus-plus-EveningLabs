// 7.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>

std::string Encryption(std::string input);
std::string Decryption(std::string input);
std::string ReadFileTask();

using namespace std;

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	std::ofstream outfile("a.txt");
	std::string ss = "";

	std::cin >> ss;
	outfile << Encryption(ss);
	outfile.close();

	std::string ss1 = ReadFileTask();
	ss1 = Decryption(ss1);
	std::cout << ss1;
	return 0;
}

std::string Encryption(std::string input)
{
	std::string out = input;
	int inputl = input.length();
	for (int i = 0; i < inputl; i++)
	{	
		if (out[i] == 'а' || out[i] == 'А') {
			out[i] = 'ц';
		}
		if (out[i] == 'о' || out[i] == 'О') {
			out[i] = 'ш';
		}
		if (out[i] == 'и' || out[i] == 'И') {
			out[i] = 'щ';
		}
	}
	return out;
}

std::string Decryption(std::string input)
{
	std::string out = input;
	int inputl = input.length();
	for (int i = 0; i < inputl; i++)
	{
		if (out[i] == 'ц') {
			out[i] = 'а';
		}
		if (out[i] == 'ш') {
			out[i] = 'о';
		}
		if (out[i] == 'щ') {
			out[i] = 'и';
		}
	}
	return out;
}

std::string ReadFileTask()
{
	std::string line = "";
	std::ifstream infile("a.txt");
	if (infile.is_open())
	{
		while (getline(infile, line))
		{
			std::cout << line << '\n';
		}
		infile.close();
	}
	return line;
}

//Задачи шифровки.Составить программу, которая вводит строку с клавиатуры; 
//признак окончания ввода – нажатие клавиши Enter, шифрует введенный текст в файл на 
//диске по определенному алгоритму.Программа должна считывать эту строку из файла и 
//далее дешифровать текст, выводя его на экран и записывая в выходной файл.
//В программе реализовать следующие действия :
//– ввод с клавиатуры исходной строки текста и запись в файл a.txt;
//– считывание строки из файла и вывод на экран;
//– шифровка текста;
//– расшифровка.
//
//
//Каждая из букв «а», «о», «и» заменяется соответственно на «ц», «ш», «щ».