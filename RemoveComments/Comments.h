#pragma once
#include <fstream>
using namespace std;

class Comments
{
public:

	void remove_comments(ifstream&, ofstream&); 
	void checkCommentsSlashSlash(string&, bool&, ofstream&);
	void checkComments(string&, bool&, ofstream&);

	bool check_file(ifstream &source, string name);

};

