#include "invindex.h"

InvIndex::InvIndex(ifstream& source,char* name)
{
	char word[20];
	int WordNum=1,SentNum=1;
	InvTextFile.open(name);
	source>>word;
	while (word){
		Insert(word,WordNum,SentNum);
		WordNum++;
		SentNum++;
		source>>word;
	}
	InvTextFile<<m_index;
	InvTextFile.close();

}

void InvIndex::Insert(char* word, int Wordnum, int SentNum)
{
	WordInfo temp(m_index[word]);
	temp.Update(WordNum,SentNum);
	m_index[word]=temp;
}

ostream& operator<<(ostream& out, myMap& index)
{
	myMap::iterator mapItr=index.begin();
	while(mapItr!=index.end())
	{
		out<<mapItr->first<<" ";
		out<<mapItr->second;
		mapItr++;
	}
	return out;
}