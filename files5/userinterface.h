#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include "invindex.h"

using namespace std;

class UserInterface
{
public:
	UserInterface(ifstream& in, ofstream& out);
	void menu(ifstream& in, ofstream& out);
	char* Create_index (ifstream& source,char* fileName);
};
#endif