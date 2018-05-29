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

Void InvIndex::Insert(char* word, int Wordnum, int SentNum)
{
	WordInfo temp(m_index[word]);
	temp.update(WordNum,SentNum);
	m_index[word]=temp;
}
