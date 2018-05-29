#include "userinterface.h"
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	UserInterface Menu(in,out);
	in.close();
	out.close();
	cout<<"bye"<<endl;
}
