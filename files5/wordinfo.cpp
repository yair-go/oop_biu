#include "wordinfo.h"

WordInfo::WordInfo(const WordInfo& w_i)
{
	int i;
	for (i=0;i<w_i.v.size();i++)
	{
		v[i]=w_i.v[i];
	}
	apper=w_i.apper;
} 

void WordInfo::Update(int WordNum,int SentNum)
{
	InstaceInfo i(WordNum,SentNum);
	v.push_back(i);
}	

ostream& operator<<(ostream& out, WordInfo& info)
{
	out<<info.apper;
	for(int i=0;i<info.v.size();i++)
		out<<info.v[i];
	out<<endl;
	return out;
}

