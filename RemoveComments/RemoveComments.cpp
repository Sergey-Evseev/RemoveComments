//HW � ��������� 5: ������� ����������� �� CPP ����� - ����� ����� // � // ��� /* �  */

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
	ifstream source; // ���������� �������� ������ fstream
	ofstream target;
	
	//���� �������� �������� �����//
	do {
		cout << "������� ��� ����� ��� ��������������: ";
		cin >> infile;
		source.open(infile);//���������� ������ � ������
	} while (!source.is_open()); //��� while (temp.fail()); - is_open() �����. true ���� ���� ������ � ������ � ���� �������� ������
	
	//����� � ������ ��������������� �����//
	cout << endl;
	string line; //��������� ��������� ����������
	while (getline(source, line))//���� ������� �������� ������ �� ����� ���������� �� � ������
	{		
		cout << line << endl;
	}
	cout << "================= ����� ��������������� ����� ===================" << "\n\n";	
	source.close();
	

	cout << "������� ��� ��� ����������� �����: ";
	cin >> outfile;
	cout << endl;
	
	source.open(infile);//������������� ������� ���������� ������� ������� (��� (infile.c_str()))
	target.open(outfile); //(��� outfile.c_str() - ������� c_str() ���������� ��������� �� ������ ���������� ������� ��������� 

	//������ �������� �������//
	readFile.remove_comments(source, target); //����� �������� �������

	source.close();//�������� ������� (������� ������� �� ������)	
	target.close();

	return 0;
}