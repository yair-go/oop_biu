#include "worker.h"
/***********************************************************************************************
*function name : constructor                                                                      
*The Input: name, ID, pQ                                                      
*The Output: none       
*function operation :  init a new line string 
***********************************************************************************************/


Admin::Admin(char* iname, int iID,Queue* iQ)
{
	salary=3000;
	set_worker(iname,iID,iQ);
} 

/***********************************************************************************************
*function name : update salary                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  update the salary 
***********************************************************************************************/

int Admin::update_salary()
{
	salary+=5;
  return salary;
}

/***********************************************************************************************
*function name : add card                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a new card 
***********************************************************************************************/

void Admin:: add_card()
{
	int num,ser,client;
	Card* new_card;
	new_card=new Card;
	cin>>num>>ser>>client;
	if ((ser<1)||(ser>3)||(pQ->IsMember(num))||(client>9999)||(client<1000)) throw "1";
	new_card->setCard(num,ser,client);
	salary=update_salary();
	pQ->Insert(new_card);
}

/***********************************************************************************************
*function name : menu                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  admin menu 
***********************************************************************************************/

void Admin:: menu()
{
   int choice;
   do{
   try{
   	cin>>choice;
   	switch (choice)
   	{
		case 1:
			add_card();
		  	break;
		case 2:
			print_salary(salary+(salary/10));
		case 4:
			break;
		default:
			cout<<"Not available"<<endl;
			break;
   	}
   }
   catch(...){
   	cout<<"Not available"<<endl;
   }
   }while (choice!=4);
}

