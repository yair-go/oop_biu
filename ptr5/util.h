#ifndef UTIL_H
#define UTIL_H


#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

#define input "input.txt"
#define output "output.txt"

FILE *pinput, *poutput;


//-------------------------------------------------------------------------------------------------
//------declaration   -----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void newstack(char*** ps,int c);
void DisplayError();
char** push(char* ps, char* el);
char** pop(char* ps);
void top(char** ps);
void IsEmpty(char** ps);
int capacity(char** ps);

#endif
