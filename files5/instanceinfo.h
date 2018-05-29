#ifndef INSTANCE_INFO_H
#define INSTANCE_INFO_H

class InstanceInfo
{
private:
	int sentence;
	int word_in_sentence;
public:
	InstanceInfo(int w,int s);
	friend ostream& operator<<(ostream&, InstanceInfo&);

};	


#endif