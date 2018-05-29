#ifndef INV_INDEX_H
#define INV_INDEX_H

#include <fstream>
#include "wordinfo.h"
#include <map>
#include <iostream>
using namespace std;
struct ltstr
{
	bool operator()(const char* s1, const char* s2) const
	{
		return strcmp(s1, s2) < 0;
	}
};
	 
typedef map<const char*,WordInfo,ltstr> myMap;

class InvIndex
{
private:
	ofstream InvTextFile;
	myMap m_index;
	
public:
	InvIndex(ifstream& source,char* name);
	void Insert(char* word, int Wordnum, int SentNum);
	friend ostream& operator<<(ostream&,myMap&);
};

#endif 
