#include "Comments.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//������� ������ �������� ����� � ������ �� ���� //
void Comments::checkCommentsSlashSlash(string& line, bool& flag, ofstream& Target)//�������� ��������� �� ������
{
	if (!flag)
	{
		for (int i = 0; i < line.length(); ++i)//����� ������� ��������� ������
		{
			if ((line.at(i) == '/') && (line.at(i + 1) == '/')) // ���� ������ �������� ��� ������ '/' ��������� ������� ������
				break;
			else
				Target << line[i]; // ����� ���������� ������ ������� i � ��������� �����
			cout << line.at(i);  //����� ���������� �������� ������ � ������ (��� cout << line[i]);///
		}
		Target << endl;//�������� � �������� ���� ������� ������
		cout << endl; //����� �������� ������		
	}	
}//����� checkCommentsSlashSlash

//������� ������ /* � */ � ������� �� ������ ������������ � ������ ����� /* ��� ������ ("/*")
void Comments::checkComments(string& line, bool& flag, ofstream& Target)
{
	int count = 1; //��������������� 1, ��� ��� ���� �� ������ "/*" ���� �� ����� ���������� �� true (� 40-� ������ ����)
	if (line.find("/*") < line.length()) // ���� � ������ ����� "/*"  
	//������� find() ���� ������ �� ������ �� ������� ���������� ��������� ������� �������� ������� ������� � ���������� �� �������	
	{
		count = 0; //�� ��������� ��� �� ������� � ��������� �� ������� /*
		for (int i = 0; i < line.find("/*"); ++i) { //�������� �������� �� "/*" ������� � �� ������� �����������
			if ((line.at(i) == '"')) //���� ������ �� ������� /* �������� ������� ������� 
				count++; //����������� ������� ��� ������ ���������� �������
		}
	} 
	if ((count % 2) == 0) //� ������ �������/�������� ���-�� ������� " �� /* � ���������� ������� � checkCommentsSlashSlash �� ������� � � ����� �� ��������
		flag = true;    

	checkCommentsSlashSlash(line, flag, Target); //����� ������� ������ "//" (���� flag==false)
	
	if (flag)
	{
		if (line.find("*/") < line.length()) //���� ����� ����������� */ 
			flag = false;
	}	
}//����� checkComments()//

//������� ���������� ����� � �������� �� � checkComments()//
void Comments::remove_comments(ifstream& Source, ofstream& Target)
{
	string line; //���. ������ ��� �������� ����������� ������ (���������� ������)
	bool flag = false;//���� ��� ���� ����� ������ '//' � checkCommentsSlashSlash � ���������� ��� ������ � ��������� �����

	while (!Source.eof()) //���� �� ��������� ����� �����
	{
		getline(Source, line); // ������ ������ �� ������� �� Source � �������� � line			
		checkComments(line, flag, Target);//�������� ������������ ��� ����������� ������		
	}
}//����� remove_comments()//
