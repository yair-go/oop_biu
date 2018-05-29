#include "worker.h"

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: name,ID, rank, priority queue                                                 
*The Output: none      
*function operation :  init a new manager
***********************************************************************************************/

Manager::Manager(char* iname, int iID, int ideg, Queue* iQ)
{
	set_worker(iname,iID,iQ);
	deg=ideg;
	salary=5000+(500*deg);
}

/***********************************************************************************************
*function name : destructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  
***********************************************************************************************/

Manager:: ~Manager()
{
}

/***********************************************************************************************
*function name : confirm                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  confirm card
***********************************************************************************************/

void Manager:: confirm()
{
	int ipriority;
	if (pQ->find_new()) {
		cin>>ipriority;
		if ((ipriority<1)||(ipriority>10)) throw 1;
		pQ->change_pririoty(ipriority);
	}
	else throw 1;
	update_salary();
}

/***********************************************************************************************
*function name : show cards                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  show all cards 
***********************************************************************************************/

void Manager:: show_cards()
{
	pQ->print();
}

/***********************************************************************************************
*function name : close card                                                                      
*The Input: card number                                                        
*The Output: none       
*function operation :  delete card from queue 
***********************************************************************************************/

void Manager:: close_card(int card_num)
{
	pQ->Delete(card_num);
}

/***********************************************************************************************
*function name : update salary                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  update the mananger salary
***********************************************************************************************/

int Manager:: update_salary()
{
	salary+=10;
   return salary;
}

/***********************************************************************************************
*function name : menu                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  show the menu
***********************************************************************************************/


void Manager:: menu()
{
	int choice,card_num;
	do{
	try{
		cin>>choice;
   		switch (choice)
   		{
      			case 1:
		  		confirm();
		  		break;
      			case 2:
		  		show_cards();
		  		break;
      			case 3:
				cin>>card_num;
				if (pQ->IsMember(card_num))
		  			close_card(card_num);
				else throw "1";
		  		break;
	  		case 4:
		  		print_salary(salary);
		  		break;
	  		case 7:
		  		break;
      			default:
         			cout<<"Not available"<<endl;
		 		break;
   		}
	}
	catch (...) {
		cout<<"Not Available"<<endl;
	}
	}while (choice!=7);
}