#ifndef WORD_INFO_H
#define WORD_INFO_H

#include <vector>
#include "instanceinfo.h"
using namespace std;
class WordInfo
{
private:
	int apper;
	vector<InstanceInfo> v;

public:
	WordInfo ();
	WordInfo (WordInfo& w_i);
	void Update(int WordNum,int SentNum);
	friend ostream& operator<<(ostream&, WordInfo&);
	


};
#endif