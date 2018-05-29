#ifndef COMMPANY_H
#define COMMPANY_H

#include "worker.h"
#include "util.h"

class Commpany
{
private:
   
   Queue* C_Q;
public:
   Worker** Emploee;
   Commpany();
   ~Commpany();
   void init_com();
   Worker* find(int worker_num);
   int chaek_uniq(int iID);
};

#endif
