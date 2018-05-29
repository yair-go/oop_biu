#include <iostream.h>
#include <string.h>
#include "game.h"
#include "player.h"
#include "bet.h"

/***********************************************************************************************
*function name : consturctor                                                                       
*The Input: none                                                        
*The Output: none       
*function operation :  actually the all game is happen
***********************************************************************************************/

Game::Game()
{
   int i,B=0,shibus_cnt=0,first,where,j;
   Bet turn;
   char mashuv[6],p_name[11],*real_winner;
    Player *p;
    do {
       cin>>shibus;
    } while (shibus<0  || shibus>2);
    do{
       cin>>player_num;
   }while (player_num<2);
   p=new Player[player_num];
   for (i=0;i<player_num;i++) {
      p[i].set_name();
   }
   do {
      cin>>min>>max;
      B=check_range(min,max);
   } while (!B);
   B=0;
   do {
      cin>>gold_num;
      B=check_range(gold_num,min,max);
   } while (!B);
   for (i=0;i<player_num;i++){
      p[i].m_min=min;
      p[i].m_max=max;
      p[i].m_gold=gold_num;
     }
    do {      
       for (i=0;i<player_num;i++){
          turn=p[i].get_bet();
          if ((turn.get_himur()>gold_num)||(turn.get_himur()==gold_num)) strcpy(mashuv,"high");
          else strcpy(mashuv,"low");
          if (turn.get_himur()==gold_num) if (shibus_cnt==shibus) strcpy (mashuv,"bingo");
                                          else {
					     if (shibus_cnt==0) { 
                                                     min_nikud=p[0].get_nikud();
                                                     real_winner=p[0].get_name();
                                                     for (j=1;j<player_num;j++) 
                                                       if (p[j].get_nikud()<min_nikud){ 
                                                         min_nikud=p[j].get_nikud();
                                                         real_winner=p[j].get_name();
						       }  
                                             }
					     shibus_cnt++; 
					  } 
          //p[i].print_name();
          cout<<p[i].get_name()<<" "<<turn.get_himur()<<": "<<turn.get_nikud()<<" "<<mashuv<<endl;
          if (strcmp(mashuv,"bingo")==0) break;
       }    
   }while (strcmp(mashuv,"bingo")!=0);
   min_nikud=p[0].get_nikud();
   winner=p[0].get_name();
   for (i=1;i<player_num;i++){
     if (p[i].get_nikud()<min_nikud) {
              min_nikud=p[i].get_nikud();
	      winner=p[i].get_name();
     }
   }
   cout<<"winner: "<<winner<<endl;   	
   if (shibus) cout<<"winner: "<<real_winner<<endl;
   /*   {	
       where=p[first].find_where(); 
      for (i=0;i<player_num;i++);
	{
         p[i].update_nikud(where);
	}
       min_nikud=p[0].get_nikud();
       winner=p[0].get_name();
       for (i=1;i<player_num;i++){
         if (p[i].get_nikud()<min_nikud) {
              min_nikud=p[i].get_nikud();
	      winner=p[i].get_name();
      }
       }
       cout<<"winner: "<<winner<<endl; 
   }*/
   delete (p);
}

/***********************************************************************************************
*function name : check_range                                                                       
*The Input: 2 numbers                                                        
*The Output: 0 or 1       
*function operation :  check if the range if legal
***********************************************************************************************/

int Game::check_range(int low, int high)
{
	if ((low>high) || (low<=0) || (high<0)) return 0;
	else return 1;
}

/***********************************************************************************************
*function name : check_range                                                                       
*The Input: 3 numbers                                                        
*The Output: 0 or 1       
*function operation :  check if the number is positive and between the other
***********************************************************************************************/

int Game:: check_range(int num, int low, int high)
{
	if ((num<0)||(num<low)||(num>high)) return 0;
	else return 1;
}
