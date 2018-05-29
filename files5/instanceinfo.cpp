#include "instanceinfo.h"

InstanceInfo::InstanceInfo(int w,int s)
	{
		word_in_sentence=w;
		sentence=s;
	} 
ostream& operator<<(ostream& out,InstanceInfo& info)
{
	out<<" sentence: "<<info.sentence<<" word: "<<info.word_in_sentence;
	return out;
}