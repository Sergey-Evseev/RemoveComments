//”далить комментарии из CPP файла - текст между // и // или /* и  */

#include <iostream>
#include <fstream>
#include <string>
#include "Comments.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	Comments readFile;

	string infile, outfile; //строки дл€ имен файлов чтени€ и записи
	ifstream source; // объ€вление объектов fstream
	ofstream target;
	//do {
	//	cout << "¬ведите им€ файла дл€ редактировани€: ";
	//	cin >> infile;
	//} while (source.fail());//пока файл не откроетс€ повтор€ть запрос файла
	
	Comments check;
	do {
		cout << "¬ведите им€ файла дл€ редактировани€: ";
		cin >> infile;		
	} while (!check.check_file(source, infile));
		

	cout << "¬ведите им€ дл€ измененного файла: ";
	cin >> outfile;

	source.open(infile.c_str());//открытие файла по переданному строковому адресу
	target.open(outfile.c_str()); //функци€ c_str() возвращает указатель на массив содержащий текущую подстроку

	readFile.remove_comments(source, target); //вызов основной функции

	source.close();//закрытие потоков
	target.close();

	return 0;

}