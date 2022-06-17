#include <iostream>
#include <fstream>
#include <string>
#include "Comments.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Comments readFile;

	string infile, outfile; //имена файлов для чтения и записи
	ifstream source; // объекты fstream
	ofstream target;
	do {
		cout << "Введите имя файла: ";
		cin >> infile;
	} while (source.fail());//пока файл не откроется повторять запрос файла

	cout << "Enter Output File Name: ";
	cin >> outfile;

	source.open(infile.c_str());
	target.open(outfile.c_str());

	readFile.remove_comments(source, target); //вызов основной функции

	source.close();//закрытие потоков
	target.close();

	return 0;

}