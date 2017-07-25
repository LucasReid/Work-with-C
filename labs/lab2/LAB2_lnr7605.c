/*
* Program:	lab2_lnr7605.c	 Due Date: 09-18-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Declare and use complex data types using struct.
*		Use typedef to make code easier to read.
*		Create string variables.
*		Use functions in string.h to manipulate strings.
*		Use sprint to build strings.
*		Understand how arguments are passed to main.
*		Use the arguments in a program.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS  6
#define MAX_LEN  100

typedef struct
{
	int day;
	int month;
	int year;
}dateType;

int main(int argc, char** argv)
{
	int count = 0;
	char dateArray[15];
	dateType date;
	
	if(argc < MAX_ARGS)
	{
		printf("not enough args\n");
		return 1;
	}
	for(int i=0; i<argc; i++)
	{
		
		if(i>MAX_ARGS)
		{
		printf("To many arguments!\n");
		return 1;
		}
		printf("Argument %d, = %s\n", count, argv[i]);
		count++;
	}
	
	
	char greeting[MAX_LEN +1];
		
	
	strcpy(greeting, argv[1]);
	strcat(greeting, " ");
	strcat(greeting, argv[2] ); //add World
	
	date.month = atoi(argv[3]);
	date.day = atoi(argv[4]);
	date.year = atoi(argv[5]);
	sprintf(dateArray,"%d/%d/%d", date.month, date.day, date.year);
	printf("%s:\t %s\n ", greeting,dateArray );
	 
	return 0;
}		
