#include "player.h"
#include "bet.h"
#include <string.h>
#include <iostream.h>

/***********************************************************************************************
*function name : get_bet                                                                       *
*The Input: none                                                                               *
*The Output: one bet                                                                           *
*The function operation : the function get variable from the user and return object of bet     *
***********************************************************************************************/
Bet Player::get_bet()
{ 
   int himur,nihus,nikud=0,B1=0,B2=0,a,i;
   Bet *ezer;
   do {
      cin>>himur>>nihus;
      B1=check_range(himur,m_min,m_max);
      B2=check_range(nihus,1,2);
  } while ((B1==0)||(B2==0));
  a=m_gold-himur;
  if (a<0) a*=-1;
  if (a<10) if (nihus==1) nikud=a;
            else nikud=a*2;
  else if (nihus==1) nikud=a*2;
      else nikud=a;
    if (counter>4) {
                  ezer=new Bet[counter];
		  for (i=0;i<=counter;i++){
		     ezer[i]=history[i];
		  }
		  history=new Bet[counter*2];
		 }
  history[counter].set_bet(himur,nihus,nikud);
  counter++;
  Mnikud+=nikud;
  return history[counter-1]; 
}

/***********************************************************************************************
*function name : check_range                                                                       
*The Input: 3 numbers                                                        
*The Output: 0 or 1       
*function operation :  check if the number is positive and between the other
***********************************************************************************************/

int Player:: check_range(int num, int low, int high)
{
	if ((num<0)||(num<low)||(num>high)) return 0;
	else return 1;
}

/***********************************************************************************************
*function name : update_nikud                                                                       
*The Input: the the last index that considersd                                                                              
*The Output: none                                                                           
*The function operation : the function update the nikud of each player to his real nikud    
***********************************************************************************************/

void Player:: update_nikud(int where)
{
   int i,num;
   Mnikud=0;
   for (i=0;i<=where;i++){
      num=history[i].get_nikud();
      Mnikud+=num;
   }
}

/***********************************************************************************************
*function name : find_where                                                                     
*The Input: none                                                                              
*The Output: where the first gold number                                                                           
*The function operation : return where the first gold number  
***********************************************************************************************/

int Player:: find_where()
{
   int i=0;
   while (history[i].get_himur()!=m_gold) i++;
   return i;
}

/***********************************************************************************************
*function name : desturctor                                                                     
*The Input: none                                                                              
*The Output: none                                                                           
*The function operation : delete the history 
***********************************************************************************************/

Player:: ~Player()
{
   delete (history);
}