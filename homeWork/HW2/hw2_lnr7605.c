/*
* Program:	hw2_lnr7605.c	 Due Date: 09-18-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Create a program that reads intigers from an external file and:
* 	1. Stores the numbers in a two dimensional array and displays the 
*		array in a 5X10 graph.
* 	  
*	2. Finds the SUM, MIN, MAX, and AVG of the array of numbers
* 		and displays them below the array of values. 
*		
* 		Sales Summary for 2016:
*			Sales Total: 3435
*			Sales Max: 99	
*			Sales Min:	18
*			Sales Avg: 68.7000
*
*/
#include <stdio.h> 

#define MAX_COLUMNS	5
#define MAX_ROWS 	10

int main(int argc, char** argv)
{	
	int numbers[MAX_ROWS][MAX_COLUMNS];
	int i, j, max=0, min, sum=0, count=0;
	double average;
	

	FILE *InFile;
	InFile = fopen("bicycleSales.txt", "r");
	if(InFile==NULL)
	{
		printf("File for input not opened\n");
		return 1;
	}
	FILE *OutFile;
	OutFile = fopen("YearlySales.txt", "w");
	if(OutFile==NULL)
	{
		printf("OutFile not Created\n");
		return 1;
	}
	for(i=0; i<MAX_ROWS; i++)
	{
		for(j=0; j< MAX_COLUMNS; j++)
		{
			count++;
			fscanf( InFile, "%d",&numbers[i][j]);
			fprintf(OutFile, "%d\t", numbers[i][j]);
			sum += numbers[i][j];
			if(numbers[i][j] > max)
			{
				max = numbers[i][j];
				min=max;
			}
			
					
		}
		fprintf(OutFile,"\n");
	}
	for(i=0; i<MAX_ROWS; i++)
	{
		for(j=0; j< MAX_COLUMNS; j++)
		{
			if(numbers[i][j] <min)
			{
				min = numbers[i][j];
			}		
		}
	}
	average = (double)sum/count;
	
	fprintf(OutFile,"\n");
	fprintf(OutFile,"Sales Summary for 2016:\n");
	fprintf(OutFile,"\tSales Total:\t%d\n", sum);
	fprintf(OutFile,"\tSales Max:\t%d\n", max);
	fprintf(OutFile,"\tSales Min:\t%d\n", min);
	fprintf(OutFile,"\tSales Avg:\t%f\n", average);
	
	return 0;
}
