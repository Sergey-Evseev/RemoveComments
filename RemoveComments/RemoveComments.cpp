//������� ����������� �� CPP ����� - ����� ����� // � // ��� /* �  */

#include <iostream>
#include <fstream>
#include <string>
#include "Comments.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	Comments readFile;

	string infile, outfile; //������ ��� ���� ������ ������ � ������
	ifstream source; // ���������� �������� fstream
	ofstream target;
	//do {
	//	cout << "������� ��� ����� ��� ��������������: ";
	//	cin >> infile;
	//} while (source.fail());//���� ���� �� ��������� ��������� ������ �����
	
	Comments check;
	do {
		cout << "������� ��� ����� ��� ��������������: ";
		cin >> infile;		
	} while (!check.check_file(source, infile));
		

	cout << "������� ��� ��� ����������� �����: ";
	cin >> outfile;

	source.open(infile.c_str());//�������� ����� �� ����������� ���������� ������
	target.open(outfile.c_str()); //������� c_str() ���������� ��������� �� ������ ���������� ������� ���������

	readFile.remove_comments(source, target); //����� �������� �������

	source.close();//�������� �������
	target.close();

	return 0;

}