//#include "util.h"

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

//-------------------------------------------------------------------------------------------------
//------implementation-----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

/************************************************************************
 * Function name: newstack						*
 * The Input: none							*
 * The output: address of allocated memory				*
 * The function operation: creating a stack with 2 places		*
 ************************************************************************/
void newstack(char ***ps,int c)
{
	if ((ps[c]=(char**)calloc(4,sizeof(char**)))==NULL) //find place for stack
		exit(1); //cant find enough memory to allocate the stack list to
	ps[c][0]=(char*)calloc(20,sizeof(char*));
	ps[c][1]=(char*)calloc(20,sizeof(char*));
	strcpy(ps[c][0],"11";
	strcpy(ps[c][1],"");
}//newStack

/************************************************************************
 * Function name: Display_Error						*
 * The Input: none							*
 * The output: none							*
 * The function operation: displaying an error message			*
 ************************************************************************/

void DisplayError()
{
	fprintf(poutput,"error\n");
}//DisplayError


/************************************************************************
 * Function name: push							*
 * The Input: element to put into the stack				*
 * The output: the stack's address					*
 * The function operation: putting an element into the stuck		*
 ************************************************************************/

char** push(char** ps, char* el)
{
	int NewCapacity;

	ps[1]=ps[1]+1;
	ps[ps[1]+1]=el;

	if (capacity(ps)>=90) //if theres no more room in the stack
	{
		NewCapacity=(int)((ps[1]/0.7)+0.5);
		if( (ps=(char**)realloc(ps,(NewCapacity+2)*sizeof(char*) )) == NULL )
			exit(1); //cant find enough memory to allocate the stack to
		ps[0]=NewCapacity;
	}
	return ps;
}//push

/************************************************************************
 * Function name: pop							*
 * The Input: none							*
 * The output: the stack's address					*
 * The function operation: deleting the last element from the stuck	*
 ************************************************************************/
char** pop(char** ps)
{
	if (ps[1]>0)
	{
		ps[1]=ps[1]-1;
		ps[0]=ps[0]-1;
		if ( (ps=(char**)realloc(ps,(ps[0]+2)*sizeof(char*) )) == NULL )
			exit(1); //cant find enough memory to allocate the stack to
	}
	else DisplayError(); //there are no elements in the stack!

	return ps;

}//pop

/************************************************************************
 * Function name: top							*
 * The Input: none							*
 * The output: none							*
 * The function operation: displaying the last element entered		*
 ************************************************************************/

void top(char** ps)
{
	if (ps[1]!=0) fprintf(poutput,"%s\n",ps[ps[1]+1]);
	else DisplayError(); //there are no elements in the stack
}//top

/************************************************************************
 * Function name: isEmpty						*
 * The Input: none							*
 * The output: none							*
 * The function operation: displaying a message whater the stack is	*
 *	empty or not							*
 ************************************************************************/

void IsEmpty(char** ps)
{
	if (ps[1]==0)
		fprintf(poutput,"true\n");
	else fprintf(poutput,"false\n");
}//isEmpty

/************************************************************************
 * Function name: capacity						*
 * The Input: none							*
 * The output: precentage of occupied elements in the stack		*
 * func operation: displaying the % of occupied elements in the stack	*
 ************************************************************************/
int capacity(char** ps)
{
	return (int)(0.99 + ((double)(ps[1]*100)/ps[0]) );
}//capacity


/*********************************************************************
 * Program name: targil 5, quesion 2                                 *
 * The operation: creating and managing an undeclared-sized stack    *
 *********************************************************************/


/********************************************************************
 * Function name: main												*
 * The Input: none													*
 * The output: none													*
 * The function operation: the program itself						*
 ********************************************************************/

int main()
{
	int choice=0;
	int counter=0; //counter=how many stacks exists
	char element[256];
	char ***pstacklist=NULL; //pointer to an array of pointers to stacks

	pinput=fopen(input,"r");
	if (pinput==NULL) exit(1); //cant find the file "input.txt"
	poutput=fopen(output,"w");

	pstacklist=(char***)calloc(3,sizeof(char**)); 

	fscanf(pinput,"%d",&choice);
	while (choice!=9)
	{
		switch (choice) 
		{
		case 1:
			++counter;
			if ((pstacklist=(char ***)realloc(pstacklist,counter*sizeof(char**)))==NULL)
				exit (1); //INSUFFICENT MEMORY
			newstack(pstacklist,counter-1);
			break;

		case 2:
			fscanf(pinput,"%d",&choice);

			if ((choice<=counter)&&(choice>0)) //if stack exists
			{
				fscanf(pinput,"%s",element);
				pstacklist[choice-1]=push(pstacklist[choice-1],element);
			}
			else 
			{
				DisplayError(); //stack doesnt exist
				fscanf(pinput,"%s",element); //getting rid of extra number
			}
			break;

		case 3:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0)) top(pstacklist[choice-1]); //if stack exists
			else DisplayError();
			break;

		case 4:
			fscanf(pinput,"%d",&choice);
			 if ((choice<=counter)&&(choice>0)) pop(pstacklist[choice-1]); //if stack exists
				else DisplayError();
			break;

		case 5:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0)) IsEmpty(pstacklist[choice-1]); //if stack exists
			else DisplayError();
			break;

		case 6:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0))  //if stack exists
			{
				free(pstacklist[choice-1]);
				while (choice<counter)
				{
					pstacklist[choice-1]=pstacklist[choice];
					++choice;
				}
				--counter;
				if ((pstacklist=(int **)realloc(pstacklist,counter*sizeof(int*)))==NULL)
						exit (1); //INSUFFICENT MEMORY
			}
			else DisplayError();
			break;

		case 7:
			fprintf(poutput,"%d\n",counter);
			break;

		case 8:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0))  //if stack exists
			{
				element=capacity(pstacklist[choice-1]);
				fprintf(poutput,"%d\n",element);
			}
			else DisplayError(); //stack doesnt exists
			break;

		default:
			DisplayError();
		}//case
		fscanf(pinput,"%d",&choice);
	}//while

	while (counter>0)
	{
		free(pstacklist[counter-1]);
		--counter;
	}
	free(pstacklist);
	fclose(pinput);
	fclose(poutput);
	return 0;
}//main



