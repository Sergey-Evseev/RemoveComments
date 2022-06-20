#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//функция поиска двойного слэша и записи до него //
void Comments::checkCommentsSlashSlash(string& line, bool& flag, ofstream& Target)//передаем указатель на строку
{
	if (!flag)
	{
		for (int i = 0; i < line.length(); ++i)//поиск символа перебором строки
		{
			if ((line.at(i) == '/') && (line.at(i + 1) == '/')) // если строка содержит два подряд '/' завершить перебор строки
				break;
			else
				Target << line[i]; // иначе копировать символ позиции i в исходящий поток
			cout << line.at(i);  //ВЫВОД КОПИРУЕМЫХ СИМВОЛОВ СТРОКИ В ПАНЕЛЬ (или cout << line[i]);///
		}
		Target << endl;//записать в конечный файл перевод строки
		cout << endl; //ВЫВОД перевода строки		
	}	
}//конец checkCommentsSlashSlash

//функция поиска /* и */ с защитой от ложных срабатываний в случае ввода /* как строки ("/*")
void Comments::checkComments(string& line, bool& flag, ofstream& Target)
{
	int count = 1; //инициализирован 1, так как если не найдет "/*" флаг не будет установлен на true (в 40-й строке кода)
	if (line.find("/*") < line.length()) // если в строке нашли "/*"  
	//функция find() ищет вперед по строке до первого нахождения подстроки которая содержит искомые символы и возвращает ее позицию	
	{
		count = 0; //то проверяем нет ли кавычек в подстроке до символа /*
		for (int i = 0; i < line.find("/*"); ++i) { //проверка является ли "/*" строкой а не началом комментария
			if ((line.at(i) == '"')) //если строка до символа /* содержит двойные кавычки 
				count++; //увеличивать счетчик при каждом нахождении кавычек
		}
	} 
	if ((count % 2) == 0) //в случае четного/нулевого кол-ва кавычек " до /* в предыдущем условии в checkCommentsSlashSlash не заходим и в поток не передаем
		flag = true;    

	checkCommentsSlashSlash(line, flag, Target); //вызов функции поиска "//" (если flag==false)
	
	if (flag)
	{
		if (line.find("*/") < line.length()) //если нашли закрывающий */ 
			flag = false;
	}	
}//конец checkComments()//

//функция считывания строк и передачи их в checkComments()//
void Comments::remove_comments(ifstream& Source, ofstream& Target)
{
	string line; //доп. строка для хранения прочитанной строки (изначально пустая)
	bool flag = false;//флаг для того чтобы искать '//' в checkCommentsSlashSlash и передавать там данные в исходящий поток

	while (!Source.eof()) //пока не достигнут конец файла
	{
		getline(Source, line); // читать строку за строкой из Source и помещать в line			
		checkComments(line, flag, Target);//проверка комментариев для прочитанной строки		
	}
}//конец remove_comments()//
