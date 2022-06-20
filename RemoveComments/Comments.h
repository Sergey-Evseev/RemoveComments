#pragma once
#include <fstream>
using namespace std;

class Comments
{
public:

	void remove_comments(ifstream&, ofstream&);// 
	void checkCommentsSlashSlash(string&, bool&, ofstream&); //функция поиска двойного слэша и записи до него
	void checkComments(string&, bool&, ofstream&);//функция поиска /* и */ с защитой от ложных срабатываний в случае ввода /* как строки ("/*") 

};

