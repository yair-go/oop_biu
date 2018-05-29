#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Queue
{
private:
     vector<Card*> pCard;
public:
	Queue();
	void Insert(Card* new_card);
	void Delete();
	int IsMember(int num);
	int find_new();
	void change_pririoty(int ipriority);
	void print();
	void Delete(int);
	char* get_status(int card_num);
	int find(int card_num);
	int lock_card(int card_num,int person);
	int get_type(int card_num);
	void release_card(int card_num);
	Card* getCard(int card_num);
	int who_lock(int card_num);
	int get_first(int ser);
	void restore();
};

class Command
{
public:
	virtual void exec()=0;
	virtual ~Command(){};
};


#endif