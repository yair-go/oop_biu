#include "card.h"
#include "date.h"
#include <iostream>
#include <string>

using namespace std;


void Card:: setCard(int num,int ser,int client)
{
	Date::getDate();
	card_num=num;
	service=ser;
	customer=client;
	date[0]=Date::getDate()->getday();
	date[1]=Date::getDate()->getmonth();
	date[2]=Date::getDate()->getyear();
	priority=-1;
	status=2;
	who=0;
}

char* Card:: get_type()
{
	switch (service)
	{
		case 1:
			return "tv";
		case 2: 
			return "phone";
		case 3:
			return "internet";
	}
}

char* Card:: get_status()
{
	switch (status)
	{
		case 2:
			return "not finished";
		case 1: 
			return "finished";
		case 3:
			return "locked";
	}
}

void Card:: print()
{
	cout<<card_num<<" "<<customer<<" "<<get_type()<<" "<<priority<<" "<<get_status();
	if (who) cout<<" "<<who;
	cout<<" "<<comment<<endl;
}

int Card::lock_card(int who_lock)
{
	if (who==0){
		who=who_lock;
		status=3;
	}
	return who;
}


istream& operator>>(istream& in,Card& c)
{
	int s;
	char t[200],e;
	in.getline(t,200);
	in.getline(t,200);
	strcat(c.comment,t);
	in>>s;
	if ((s<1)||(s>2)) throw 1;
	if ((c.status!=3)||((c.status==3)&&(s==1))) c.status=s;
	return in;
}

void Card::setdate()
{
	date[0]=(Date::getDate()->getday())-date[0];
}
