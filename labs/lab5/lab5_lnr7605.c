/*
* Program:	lab5_lnr7605.c	 Due Date: 09-25-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Get the number of the error that has occured
*		Output a human readable message about the error that occured
*		
*		
*		
*/
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char** argv){
	for(int i = 0; i<50; i++)
	{	
		printf("File not opened - error: %d\n", errno);
		printf("%s\n", strerror( errno) );
		errno++;	
	}
	FILE *InFile;
	InFile = fopen("/etc/shadow", "r");

	
	
	return 0;
}














































