#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
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
		cout << endl;		
	}
	
}//конец checkCommentsSlashSlash

void Comments::checkComments(string& line, bool& flag, ofstream& Target)
{
	int count = 1; //initialized as 1, because if don't find "/*" will not set flag true
	if (line.find("/*") < line.length()) // searching for " /* " to eliminate it and all its content.
	//the .find searchs in the forward direction for the first occurrence of a substring that matches
	//the specified sequence of characters and returns its position
	{
		count = 0;
		for (int i = 0; i < line.find("/*"); ++i) { //check if "/*" is or isn't a commentary
			if ((line.at(i) == '"'))
				count++;
		}
	}
	if ((count % 2) == 0) //in case of even quotation marks it's a commentary
		flag = true;

	checkCommentsSlashSlash(line, flag, Target); //check the "//" comments
	

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
		//cout << line << endl;             //ВЫВОД ПРОЧИТАННЫХ СТРОК В ПАНЕЛЬ//
		checkComments(line, flag, Target);//проверка комментариев для прочитанной строки		
	}//конец while	
}//конец remove_comments()
