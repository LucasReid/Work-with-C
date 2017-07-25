/*
* Program:	simpleCalclnr7605.c	 Due Date: 09-11-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Create a simple calculator that performs the following:
* 	1. Display a welcome message and then prompt the user
* 	   two anter 2 integers:
* 		Welcome to LHU Simple Calculator
*		Please enter 2 integers:
*	 2. Add and subtract the integers and display the results:
* 		The sum is:
* 		The difference is:
*
*/

#include <stdio.h>

int main (int argc, char** argv)
{

	int integer1, integer2; //user inputs
	int sum, difference;		

	printf("Welcome to the LHU Simple Calculator\n");
	printf("Please enter 2 integers\n");
	scanf("%d %d", &integer1, &integer2);

	sum=integer1+integer2;	//calulate sum
	difference = integer1-integer2;//calculate difference
	
	printf("The sum is: \t\t%d\n", sum);
	printf("The difference is: \t%d\n", difference);
	// printf("%d %d %d\n", 3,4,5);

	return 0;
}
