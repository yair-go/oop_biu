#include "date.h"
#include <iostream>

using namespace std;

Date* Date::pdate=NULL;

/***********************************************************************************************
*function name : get date                                                                      
*The Input: none                                                        
*The Output: pointer to date       
*function operation :  return the current date 
***********************************************************************************************/

Date* Date::getDate()
{
	//static Date pdate;
	if(pdate==NULL)
		pdate=new Date;
	return pdate;
}

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a date 
***********************************************************************************************/

Date::Date()
{
	day=1;
	month=1;
	year=2005;
}

int Date:: update_date()
{
	char t[10];
	int iday,imonth,iyear,flag=0;
	cin>>t;
	iday=(t[0]-48)*10+(t[1]-48);
	imonth=(t[3]-48)*10+(t[4]-48);
	iyear=(t[6]-48)*1000+(t[7]-48)*100+(t[8]-48)*10+(t[9]-48);
	if (iday>30 || iday< 0 || imonth>12 || imonth<1 || iyear<2005 || iyear>2999){
		cout<<"Not available"<<endl;
		return 0;
	}
	else if ((iyear<year)||((iday<day)&&(imonth<=month)&&(iyear<=year))||((imonth<month)&&(iyear<=year))){
		cout<<"Not available"<<endl;
		return 0;
	}
	else {
		if ((month!=imonth)||(year!=iyear)) flag=1;
		day=iday;
		month=imonth;
		year=iyear;
		return flag;
	}
}

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date:: getyear()
{
	return year;
}
