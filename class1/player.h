#ifndef PLAYER_H
#define PLAYER_H
#include <iostream.h>
#include "bet.h"
class Player
{
private:
   char m_name[11];
   int check_range(int num, int low, int high);
   Bet *history;
   int Mnikud;
   int counter;
public:
  Player () {history=new Bet[4]; counter=0; Mnikud=0;}
  Bet get_bet();
  int m_min,m_max,m_gold;
  void set_name() {cin>>m_name;}
  char* get_name(){return m_name;}
  void print_name(){cout<<m_name;}
  int get_nikud(){return Mnikud;}
  void update_nikud(int where);
  int find_where();
  ~Player();
};

#endif