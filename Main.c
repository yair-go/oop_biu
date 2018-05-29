//#include "util.h"

#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define input "input.txt"
#define output "output.txt"

FILE *pinput, *poutput;


//-------------------------------------------------------------------------------------------------
//------declaration   -----------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

void newstack(char*** ps,int c);
void DisplayError();
char** push(char** ps, char* el);
char** pop(char** ps);
void top(char** ps);
void IsEmpty(char** ps);
int capacity(char** ps);
int char_number(char** ps);

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
	strcpy(ps[c][0],"11");
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
	int NewCapacity,i;

	strcat(ps[1],"1");
	ps[strlen(ps[1])+1]=(char*)calloc(20,sizeof(char*));
	strcpy(ps[strlen(ps[1])+1],el);

	if (capacity(ps)>=90) //if theres no more room in the stack
	{
		NewCapacity=(int)((strlen(ps[1])/0.7)+0.5);
		if( (ps=(char**)realloc(ps,(NewCapacity+2)*sizeof(char*) )) == NULL )
			exit(1); //cant find enough memory to allocate the stack to
		strcpy(ps[0],"");
		for (i=0;i<NewCapacity;i++)
		{
			strcat(ps[0],"1");
		}
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
	int i;
	if (strlen(ps[1])>0)
	{
		strcpy(ps[1],"");
		for (i=1;i<strlen(ps[1]);i++)
		{
			strcat(ps[1],"1");
		}
		strcpy(ps[0],"");
		for (i=1;i<strlen(ps[0]);i++)
		{
			strcat(ps[0],"1");
		}
		if ( (ps=(char**)realloc(ps,(strlen(ps[0])+2)*sizeof(char*) )) == NULL )
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

char* top(char** ps)
{
	if (strlen(ps[1])!=0)  return ps[strlen(ps[1])+1];
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
	if (ps[1]=='\0')
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
	return (int)(0.99 + ((double)(strlen(ps[1])*100)/strlen(ps[0])) );
}//capacity

int char_number(char** ps)
{
	int i,cnt=0;
	for (i=2;i<strlen(ps[1])+2;i++)
	{
		cnt+=strlen(ps[i]);
	}
	return cnt;
}

void merge(char** ps1,char** ps2)
{
	char* temp;
	while (ps2[1]!='\0'){
		ps1=push(ps1,top(ps2));
		ps2=pop(ps2);
	}
	
		
}

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
	int choice=0,choice2,cnt;
	int counter=0; //counter=how many stacks exists
	char element[256];
	int num;
	char ***pstacklist=NULL; //pointer to an array of pointers to stacks

	pinput=fopen(input,"r");
	if (pinput==NULL) exit(1); //cant find the file "input.txt"
	poutput=fopen(output,"w");

	pstacklist=(char***)calloc(3,sizeof(char**)); 

	fscanf(pinput,"%d",&choice);
	while (choice!=11)
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
			if ((choice<=counter)&&(choice>0)) fprintf(poutput,"%s\n",top(pstacklist[choice-1])); //if stack exists
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
				if ((pstacklist=(char***)realloc(pstacklist,counter*sizeof(char**)))==NULL)
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
				num=capacity(pstacklist[choice-1]);
				fprintf(poutput,"%d\n",num);
			}
			else DisplayError(); //stack doesnt exists
			break;
		case 9:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0)){
				cnt=char_number(pstacklist[choice-1]);
				fprintf(poutput,"%d\n",cnt);
			}
			else DisplayError();
			break;
		case 10:
			fscanf(pinput,"%d",&choice);
			if ((choice<=counter)&&(choice>0)){
				fscanf(pinput,"%d",&choice2);
				if ((choice2<=counter)&&(choice>0)){
					merge(pstacklist[choice-1],pstacklist[choice2-1]);
					free(pstacklist[choice2-1]);
					while (choice2<counter)
					{
						pstacklist[choice2-1]=pstacklist[choice2];
						++choice2;
					}
					--counter;
					if ((pstacklist=(char***)realloc(pstacklist,counter*sizeof(char**)))==NULL)
						exit (1); //INSUFFICENT MEMORY
					else;
				else DisplayError();
			else DisplayError();	
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



