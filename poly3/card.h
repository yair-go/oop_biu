#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
public:
	int date[3];
	int card_num;
	int service;
	int customer;
	char comment[200];
	int priority;
	int status;
	int who;
public:
	//Card(){};
	~Card(){};
	void setCard(int,int,int);
	int getPriority(){return priority;}
	void setPriority(int x){priority=x;}
	int get_card_num(){return card_num;}
	char* get_type();
	int get_service(){return service;}
	void print();
	char* get_status();
	int lock_card(int who_lock);
	void release_card(int s) {who=0;status=s;}
	int get_date(){return date[0];}
	void setdate();
	int who_lock(){return who;}
	friend istream& operator>>(istream&,Card&);
};


#endif
