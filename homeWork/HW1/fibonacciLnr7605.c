/* 
*Program fibonacciLnr7605.c  	Due Date: 09-11-2016
*
*Author: Lucas Reid 		Course: COMP302-01
*
*Description: Create a program that converts a users inputs into a sequence of 
*	fibonacci numbers, and outputs the sequence based off of how many numbers the 
*	user wants per line.
*/

#include <stdio.h>
int fibFunction();
int main(int argc, char** argv)
{
	fibFunction();

	return 0;
}

int fibFunction()
{
	int numberOfFib, numbersPerLine = 0,count=0;//user inputs
	int first = 0, second=1, next, i;
	printf("Please Enter the amount of Fibonacci numbers you want,\nfollowed by the number of columns.\n");
	scanf("%d %d", &numberOfFib, &numbersPerLine);
	
	//printf("%d\t%d\t", first, second);

	for(i = 0; i < numberOfFib; i++)
	{

		if(i <= 1)
		{
		next=i;
		count=2;
		}	
	
		else
		{
			next= first + second;
			first = second;
			second = next;
		}
		
		printf("%d\t", next);
		if(count==numbersPerLine)
		{
		printf("\n");
		}

		
		if(count >=numbersPerLine)
		count = 0;

		count++;
	}
	
	return 0;
	
}
