#include "userinterface.h"

//extern ifstream in;
//extern ofstream out;

UserInterface::UserInterface(ifstream& in, ofstream& out)
{
	menu(in,out);
}

void UserInterface::menu(ifstream& in, ofstream& out)
{
	int choice,flag1=0;
	char filename[32];
	char* inv_name;
	inv_name=new char[32];
	ifstream source;
	do{
		in>>choice;
		switch (choice)
		{
		case 1:
			in>>filename;
			source.open(filename);
			flag1=1;
			inv_name=Create_index(source,filename);
			if (inv_name==NULL) {
				out<<"text file empty";
				flag1=0;
			}
			else {
				InvIndex inv_file(source,inv_name);
				source.close();
			}
			break;
		case 2:
			if (!flag1) break;
			
		case 3:
			if (!flag1) break;
		case 4:
			if (!flag1) break;
		case 5:
			if (!flag1) break;
		}
	} while (choice!=6);
}

char* UserInterface::Create_index (ifstream& source,char* fileName)
{
	char* invFileName=NULL;
	strcpy(invFileName,fileName);
	invFileName[strlen(invFileName)-4]='\0';
	strcat(invFileName,"_inverse.txt");
	return invFileName;
}