#include <string>
#include <iostream>
#include "util.h"

using namespace std;

void Queue:: Insert(Card* new_card)
{
	pCard.push_back(new_card);
}

int Queue:: find_new()
{
	int i;
	for(i=0;i<pCard.size();i++){
		if (pCard[i]->getPriority()==-1) {
			cout<<pCard[i]->get_card_num()<<" "<<pCard[i]->get_type()<<endl;
			return 1;
		}
	}
	return 0;
}

void Queue:: change_pririoty(int ipriority)
{
	int i=0;
	Card* temp;
	while (pCard[i]->getPriority()!=-1) i++;
	pCard[i]->setPriority(ipriority);
	while ((i!=0) && (pCard[i]->getPriority()>pCard[i-1]->getPriority())){
		temp=pCard[i-1];
		pCard[i-1]=pCard[i];
		pCard[i]=temp;
		i--;
	}
}


Queue:: Queue()
{
	
}

void Queue:: print()
{
	int i=0;
	if (pCard.empty() || (pCard.front()->getPriority()<0)) throw "Not Available";
	else 
		while ((i<pCard.size())&&(pCard[i]->getPriority()>-1)){
			pCard[i]->print();
			i++;
		}
}

void Queue:: Delete(int num)
{
	int i=find(num);
	Card* temp;
	if ((pCard[i]->getPriority())>0) throw "1";
	pCard[i]->setPriority(-2);
	pCard[i]->setdate();
	while (i+1<pCard.size())
	{
		temp=pCard[i];
		pCard[i]=pCard[i+1];
		pCard[i+1]=temp;
		i++;
	}
}

int Queue:: IsMember(int num)
{
	int i=0;
	while (i<pCard.size())
	{
		if (pCard[i]->get_card_num()==num) return 1;
		i++;
	}
	return 0;
} 

char* Queue:: get_status(int card_num)
{
	return pCard[find(card_num)]->get_status();
}

int Queue:: find(int card_num)
{
	int i=0;
	while (i<pCard.size())
	{
		if (pCard[i]->get_card_num()==card_num) return i;
		i++;
	}
}	

int Queue:: lock_card(int card_num,int person)
{
	return pCard[find(card_num)]->lock_card(person);
}

int Queue::get_type(int card_num)
{
	return pCard[find(card_num)]->get_service();
}

void Queue::release_card(int card_num)
{
	pCard[find(card_num)]->release_card(2);
}

Card* Queue::getCard(int card_num)
{
	return pCard[find(card_num)];
}

int Queue::who_lock(int card_num)
{
	return pCard[find(card_num)]->who_lock();
}

int Queue::get_first(int ser)
{
	int i=0;
	while (i<pCard.size())
	{
		if (pCard[i]->get_service()==ser) return pCard[i]->card_num;
		i++;
	}
}

void Queue::restore()
{
	int i=0;
	Card* temp;
	while (i+1<pCard.size()){
		if (pCard[i]->getPriority()==0){
			temp=pCard[i];
			pCard[i]=pCard[i+1];
			pCard[i+1]=temp;
		}
		i++;
	}
}