#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


//������� ������ �������� �����//
void Comments::checkCommentsSlashSlash(string& line, bool& flag, ofstream& Target)//�������� ��������� �� ������
{
	if (!flag)
	{
		for (int i = 0; i < line.length(); ++i)
		{
			if ((line.at(i) == '/') && (line.at(i + 1) == '/')) // ���� ������ �������� ��� ������ '//' ��������� ������� ������
				break;
			else
				Target << line[i]; // ����� ���������� ������ ������� i � ��������� �����
			cout << line.at(i);  //����� ���������� �������� ������ � ������ (��� cout << line[i]);///
		}
		Target << endl;//�������� � �������� ���� ������� ������
		cout << endl;		
	}
	
}//����� checkCommentsSlashSlash

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
	
}//����� checkComments()//


void Comments::remove_comments(ifstream& Source, ofstream& Target)
{
	string line; //���. ������ ��� �������� ����������� ������
	bool flag = false;

	while (!Source.eof()) //���� �� ��������� ����� �����
	{
		getline(Source, line); // ������ ������ �� ������� �� Source � �������� � line	
		//cout << line << endl;             //����� ����������� ����� � ������//
		checkComments(line, flag, Target);//�������� ������������ ��� ����������� ������		
	}//����� while	
}//����� remove_comments()
