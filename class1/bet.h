#ifndef BET_H
#define BET_H

class Bet
{
private:
    int Mnihus;
    int Mnikud;
    int mashov;
    int Mhimur;
public:
    Bet(){};
    static int min,max;
    int get_mashov ();
    void set_bet(int himur,int nihus, int nikud);
    void set_range(int a, int b);
    int get_himur(){return Mhimur;}
    int get_nikud() {return Mnikud;}
    
};



#endif