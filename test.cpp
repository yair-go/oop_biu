#include <iostream>
#include <string>
using namespace std;

class Father
{
	private: 
		string m_sName;
	public:
		Father (const char* sName) : m_sName(sName)
			{cout<<"constucting Father"<<endl;}
		virtual ~Father() {cout<<"Bye-Bye father"<<endl;}
};

class Son : public Father
{
	public:
		Son (const char* sName,int iID) : Father(sName), m_iID(iID)
			{cout<<"creating son"<<endl;}
		~Son () {cout<<"Bye-Bye Son"<<endl;}

	private:
		int m_iID;
};

class Brother
{
	public:
		Brother(const char* sName, int iID) : m_son(sName,iID)
			{cout<<"Creating Brother"<<endl;}
		~Brother()
			{cout<<"Bye-Bye Brother"<<endl;)
	
	private:
		Son m_son;
};

int main()
{
	Father fObj("Amrom");
	Son sObj("Moshe",8234);
	Brother bObj("Aharon",9865);
	return 0;
}
