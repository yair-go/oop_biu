#ifndef GAME_H
#define GAME_H


class Game
{
private:
   int shibus,player_num;
   int gold_num;
   char* winner;  
   char* name[11];
   int min_nikud;
   int check_range(int num, int low, int high);
   int check_range(int low,int high);
public:
   Game ();
   int min,max;
   void set_range(int a, int b);  
   void start_game(); 
   char* winner_is();
};

#endif