#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <map>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class UserInterface
{
public:
	UserInterface(ifstream& in, ofstream& out){menu(in,out);}
	void menu(ifstream& in, ofstream& out);
	char* Create_index (ifstream& source,char* filename);

#endif