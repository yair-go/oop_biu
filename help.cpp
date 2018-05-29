#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int* p;
	int a,i;
	vector<int*> vec;
	for (i=0;i<10;i++){
		cin>>a;
		p=new int;
		*p=a;
		vec.push_back(p);
	}
}