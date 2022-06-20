//Удалить комментарии из CPP файла - текст между // и // или /* и  */

#include <iostream>
#include <fstream>
#include <string>
#include "Comments.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Comments readFile;

	string infile, outfile; //строки для имен файлов чтения и записи
	ifstream source; // объявление объектов класса fstream
	ofstream target;
	
	//цикл проверки открытия файла//
	do {
		cout << "Введите имя файла для редактирования: ";
		cin >> infile;
		source.open(infile);//ассоциация потока с файлом
	} while (!source.is_open()); //или while (temp.fail()); *is_open() возвр. true если файл открыт и связан с этим объектом потока
	
	//вывод в панель первоначального файла//
	cout << endl;
	string line; //временная строковая переменная
	while (getline(source, line))//пока функция получает строки из файла записывать их в строку
	{		
		cout << line << endl;
	}
	cout << "================= КОНЕЦ ПЕРВОНАЧАЛЬНОГО ФАЙЛА ===================" << "\n\n";	
	source.close();
	

	cout << "Введите имя для измененного файла: ";
	cin >> outfile;
	cout << endl;
	//ПРОВЕРИТЬ
	source.open(infile.c_str());//инициализация потоков переданным строкой адресом
	target.open(outfile.c_str()); //функция c_str() возвращает указатель на массив содержащий текущую подстроку

	//запуск основной функции//
	readFile.remove_comments(source, target); //вызов основной функции

	source.close();//закрытие потоков (отвязка потоков от файлов)	
	target.close();

	return 0;
}