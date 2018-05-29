#include <fstream>
#include "userinterface.h"

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");



int main()
{
	UserInterface menu(in,out);

	in.close();
	out.close();
}