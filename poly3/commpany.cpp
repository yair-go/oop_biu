#include "commpany.h"
#include <iostream>
using namespace std;

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a new company
***********************************************************************************************/

Commpany:: Commpany()
{
   Emploee=new Worker* [10];
   int i;
   for (i=0;i<10; i++)
      Emploee[i]=NULL;
   C_Q=new Queue;
}

/***********************************************************************************************
*function name : init_com  
*The Input: none                                                        
*The Output: none       
*function operation :  insert worker to company
***********************************************************************************************/
void Commpany:: init_com()
{
	int Emp_num=0;
	Manager* pManage;
	Admin* pAdmin;
	Technician* pTech;
	pManage=new Manager("Danny",234,2,C_Q);
	Emploee[Emp_num]=pManage;
	Emp_num++;
	pAdmin=new Admin("Shula",280,C_Q);
	Emploee[Emp_num]=pAdmin;
	Emp_num++;
	pAdmin=new Admin("Rami",266,C_Q);
	Emploee[Emp_num]=pAdmin;
	Emp_num++;
	pTech=new Technician("Sher",244,C_Q);
	pTech->set_type(1,0,0);
	Emploee[Emp_num]=pTech;
	Emp_num++;
	pTech=new Technician("Beni",288,C_Q);
	pTech->set_type(0,2,0);
	Emploee[Emp_num]=pTech;
	Emp_num++;
	pTech=new Technician("Michal",299,C_Q);
	pTech->set_type(0,0,3);
	Emploee[Emp_num]=pTech;
	Emp_num++;
	pTech=new Technician("Ben",300,C_Q);
	pTech->set_type(1,2,0);
	Emploee[Emp_num]=pTech;
	Emp_num++;
}

Commpany::~Commpany()
{
	delete[] Emploee;
}

Worker* Commpany:: find(int worker_num)
{
	int i=0;
	while (Emploee[i]) 
	{
	    if (Emploee[i]->getID()!=worker_num) i++;
	    else return Emploee[i];
	}
	return NULL;
}


