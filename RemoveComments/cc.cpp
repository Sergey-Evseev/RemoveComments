#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//функция поиска двойного слэша//
void Comments::checkCommentsSlashSlash(string& line, bool& flag, ofstream& Target)//передаем указатель на строку
{
	if (!flag)
	{
		for (int i = 0; i < line.length(); ++i)
		{
			if ((line.at(i) == '/') && (line.at(i + 1) == '/')) // если строка содержит два подряд '//' завершить перебор строки
				break;
			else
				Target << line[i]; // иначе копировать символ позиции i в исходящий поток
			cout << line.at(i);  //ВЫВОД КОПИРУЕМЫХ СИМВОЛОВ СТРОКИ В ПАНЕЛЬ (или cout << line[i]);///
		}
		Target << endl;//записать в конечный файл перевод строки
		cout << endl; //ВЫВОД перевода строки		
	}
	
}//конец checkCommentsSlashSlash

void Comments::checkComments(string& line, bool& flag, ofstream& Target)
{
	int count = 1; //инициализирован 1, так как если не найдет "/*" флаг не будет установлен на true 
	if (line.find("/*") < line.length()) // поиск "/*" для удаления символа и содержимого внутри 
	//функция find() ищет вперед по строке до первого нахождения подстроки которая содержит искомые символы и возвращает их позицию	
	{
		count = 0;
		for (int i = 0; i < line.find("/*"); ++i) { //check if "/*" is or isn't a commentary
			if ((line.at(i) == '"')) //если строка содержит двойные кавычки 
				count++; //увеличивать счетчик
		}
	}
	if ((count % 2) == 0) //в случае четных кавычек это комментарий
		flag = true;

	checkCommentsSlashSlash(line, flag, Target); //вызов функции поиска "//"
	
	if (flag)
	{
		if (line.find("*/") < line.length()) //when it finds the end of commentary, it restarts to copy
			flag = false;
	}	
}//конец checkComments()//


void Comments::remove_comments(ifstream& Source, ofstream& Target)
{
	string line; //доп. строка для хранения прочитанной строки
	bool flag = false;

	while (!Source.eof()) //пока не достигнут конец файла
	{
		getline(Source, line); // читать строку за строкой из Source и помещать в line			
		checkComments(line, flag, Target);//проверка комментариев для прочитанной строки		
	}//конец while	
}//конец remove_comments()
