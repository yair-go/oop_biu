/*8313101 043226067 Yair Goldshtein  */
/*I use in STL vector in file util.h class Queue */
#include "commpany.h"
#include "date.h"

void err_msg()
{
	cout<<"Not available"<<endl;
}

/***********************************************************
/*Program name: polymorphism3
/*The operation: describe a connecting company 
************************************************************/
int main()
{
   Commpany wow;
   wow.init_com();
   Date::getDate();
   int choice,worker_num,i;
   do{
   	cin>>choice;
   	switch (choice)
   	{
      	case 1:
         	cin>>worker_num;
	 	if (wow.find(worker_num))
	    		wow.find(worker_num)->menu();
		else {
	    		err_msg();
	    		break;
	 	}
	 	break;
     	case 2:
         	if (Date::getDate()->update_date()) wow.init_com();
         	break;
     	case 4: 
         	break;
     	default:
        	err_msg();
		break;
    	}
    }while (choice!=4);
}
