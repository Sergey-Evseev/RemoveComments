#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



void Comments::checkCommentsSlashSlash(string& line, bool& flag, ofstream& Target)
{
	if (!flag)
	{
		for (int i = 0; i < line.length(); ++i)
		{
			if ((line.at(i) == '/') && (line.at(i + 1) == '/')) // если строка содержит два подряд // удалить содержимое
				break;
			else
				Target << line[i]; // copy the character of the position i to the Target
		}
		Target << endl;
	}
}//конец checkCommentsSlashSlash

void Comments::checkComments(string& line, bool& flag, ofstream& Target)
{
	int contaAspas = 1; //initialized as 1, because if don't find "/*" will not set flag true
	if (line.find("/*") < line.length()) // searching for " /* " to eliminate it and all its content.
	//the .find searchs in the forward direction for the first occurrence of a substring that matches
	//the specified sequence of characters and returns its position
	{
		contaAspas = 0;
		for (int i = 0; i < line.find("/*"); ++i) { //check if "/*" is or isn't a commentary
			if ((line.at(i) == '"'))
				contaAspas++;
		}
	}
	if ((contaAspas % 2) == 0) //in case of even quotation marks it's a commentary
		flag = true;

	checkCommentsSlashSlash(line, flag, Target); //check the "//" comments

	if (flag)
	{
		if (line.find("*/") < line.length()) //when it finds the end of commentary, it restarts to copy
			flag = false;
	}
}//end FFiles::checkComments


void Comments::remove_comments(ifstream& Source, ofstream& Target)
{
	string line; //auxiliar string to store the read line
	bool flag = false;

	while (!Source.eof()) // This loop is to get assure that the whole input file is read.
	{
		getline(Source, line); // To read line by line.
		//checks comments for the read line
		checkComments(line, flag, Target);

	}//end while
}//end FFiles::remove_comments
