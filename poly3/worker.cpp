#include "worker.h"

/***********************************************************************************************
*function name : set_worker                                                                      
*The Input: none                                                        
*The Output: name, ID, priority queue
*function operation :  init a worker 
***********************************************************************************************/
void Worker:: set_worker(char* iname, int num,Queue* iQ)
{
   strcpy(name,iname);
   ID=num;
   pQ=iQ;
}
 
/***********************************************************************************************
*function name :  print salary                                                                     
*The Input: salary                                                       
*The Output: none       
*function operation :  print the salary 
***********************************************************************************************/

void Worker:: print_salary(int isalary)
{
   cout<<"Your salary is: "<<isalary<<endl;
}


