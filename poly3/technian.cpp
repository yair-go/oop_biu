#include "worker.h"
#include <string>
#include "date.h"
using namespace std;

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: name, ID, priority Queue                                                        
*The Output: none       
*function operation :  init a new line string 
***********************************************************************************************/

Technician::Technician(char* iname, int iID,Queue* iQ)
{
	set_worker(iname,iID,iQ);
	salary=2000;
	m_lock=0;
} 

/***********************************************************************************************
*function name : set type                                                                      
*The Input: 3 int                                                        
*The Output: none       
*function operation :  init servuce that technician provide 
***********************************************************************************************/

void Technician::set_type(int a, int b, int c)
{
	int i;
	for (i=0;i<3;i++)
		type[i]=0;
	if (a) type[0]=1;
	if (b) type[1]=2;
	if (c) type[2]=3;
}

/***********************************************************************************************
*function name : update_salary                                                                     
*The Input: none                                                        
*The Output: none       
*function operation :  update the tech salary 
***********************************************************************************************/

int Technician::update_salary()
{
	int isal,i;
	isal=salary;
	for (i=0;i<job.size();i++)
	{
		if ((job[i]->getPriority())>-1)
			isal+=((Date::getDate()->getday())-(job[i]->get_date()));
		else 
			isal+=job[i]->get_date();
	}
	return isal;
}

void Technician:: show_cards()
{
	pQ->print();
}

int Technician::ability(int card_num)
{
	int ser;
	ser=(pQ->get_type(card_num));
	int flag=0,i;
	for (i=0;i<3;i++)
	{
		if (ser==type[i])
			flag=1;
	}
	if ((strcmp(pQ->get_status(card_num),"locked")==0)&&(ID!=pQ->who_lock(card_num)))
		flag=0;
	if (card_num!=(pQ->get_first(ser))) flag=0;
	return flag;
}

void Technician:: lock_card(int num)
{
	
	if ((ability(num))&&(m_lock==0)&&(pQ->who_lock(num)==0)){
		pQ->lock_card(num,ID);
		m_lock=1;
	}
	else throw "1";
}

void Technician:: release_card (int num)
{
	if ((ability(num))&&(ID==pQ->who_lock(num))){
		pQ->release_card(num);
		m_lock=0;
	}
	else throw "1";
}

/***********************************************************************************************
*function name : wrute to card                                                                      
*The Input: card number, char l to long, s to short                                                        
*The Output: none       
*function operation :  init a new line string 
***********************************************************************************************/

void Technician:: write_to_card(int num,char w)
{
	char g[201],e;
	try{
		if (pQ->IsMember(num)==0) throw 1;	
		if (ability(num)){
			if ((w=='l')&&(pQ->who_lock(num)!=ID)) throw 1; 
			job.push_back(pQ->getCard(num));
			job[find(num)]->print();
			cin>>*(job[find(num)]);
			if (strcmp ((job[find(num)]->get_status()),"finished")==0) {
				job[find(num)]->release_card(1);
				m_lock=0;
				job[find(num)]->setPriority(0);
				pQ->restore();
			}
		}
		else throw 1;
	}
	catch (int) {
		cout<<"Not available"<<endl;
		cin.getline(g,200);
		cin>>g;
	}
}

int Technician::find(int num)
{
	int i=0;
	while (i<job.size())
	{
		if (job[i]->get_card_num()==num) return i;
		i++;
	}
}

/***********************************************************************************************
*function name : menu                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  technician menu 
***********************************************************************************************/

void Technician:: menu()
{
	int choice,c_num;
	do{
		try
		{
			cin>>choice;
			switch (choice)
			{
				case 1:
					show_cards();
					break;
				case 2:
					cin>>c_num;
					if (pQ->IsMember(c_num))
						lock_card(c_num);
					else throw "1";
					break;
				case 3:
					cin>>c_num;
					if (pQ->IsMember(c_num))
						release_card(c_num);
					else throw "1";
					break;
				case 4:
					cin>>c_num;
					write_to_card(c_num,'s');
					break;
				case 5:
					cin>>c_num;;
					write_to_card(c_num,'l');
					break;
				case 6:
					print_salary(update_salary());
					break;
				case 7:
					break;
				default:
					throw "1";
			}
		}
		catch (...)
		{
			cout<<"Not available"<<endl;
		}
	}while(choice!=7);
}
