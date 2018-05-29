#ifndef INV_INDEX_H
#define INV_INDEX_H

#include <fstream>
#include "wordinfo.h"
#include <map>

using namespace std;
 
class InvIndex
{
private:
	ofstream InvTextFile;
		struct ltstr
	{
	  bool operator()(const char* s1, const char* s2) const
		{
			return strcmp(s1, s2) < 0;
		}
	};
	map<const char*,WordInfo,InvIndex::ltstr> m_index;
	
public:
	InvIndex(ifstream& source,char* name);
};

#endif 
