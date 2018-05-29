#ifndef WORKER_H
#define WROKER_H

#include "util.h"
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Worker
{
protected:
	char name[20];
	int ID;
	int salary;
	Queue* pQ;
public:
	//Worker();
	//~Worker();
	virtual int update_salary()=0;
	virtual void menu()=0;
	void set_worker(char* iname, int num,Queue* iQ);
	void print_salary(int isalary);
	int getID(){return ID;}
	
};

class Manager : public Worker 
{
private:
	int deg;

public:
	Manager();
	Manager(char* iname, int iID, int ideg,Queue* iQ);
	~Manager();
	void confirm();
	void show_cards();
	void close_card(int);
	int update_salary();
	void menu();
	void set_deg(int num);
};

class Admin : public Worker
{
private:

public:
	Admin();
	Admin(char* iname, int iID,Queue* iQ);
	~Admin();

	void add_card();
	int update_salary();
	void menu();
};

class Technician : public Worker
{
private:
	int type[3];
	vector<Card*> job; 
	int m_lock;
public:
	Technician();
	Technician(char* iname, int iID,Queue* iQ);
	void set_type(int a, int b, int c);
	~Technician();

	int ability(int card_num);
	void show_cards();
	void lock_card(int num);
	void release_card (int num);
	void write_to_card(int num,char w);
	int find(int num);
	int update_salary();
	void menu();
};



#endif
