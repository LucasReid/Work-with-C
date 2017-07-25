/*
* Program:	lab3_lnr7605.c	 Due Date: 09-25-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Understand how pointers work
*		Use Pointers to delcare run-time variables	
*		Change function arguments using pointers	 
*
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int *pointer;
	int i, Test;
	
	
	pointer=(int *) malloc(sizeof ( int ) );
	*pointer = 10;

	float *numberList = (float *) malloc(100*sizeof (float) );
	printf("Pointers and Runt-time Variables\n");
	if(pointer == NULL)
	{
		printf("unable to allocate memory\n");
		return 1;
	}
	
	printf("The address of pointer is %p\n",pointer);
	printf("The contents of pointer is %d\n\n",*pointer);
	

	printf("Pointers and Arrays\n");
	for(i=0; i<100; i++)
	{
		numberList[i] = i;
	}
	
	printf( "NumberList Address: %p\n", numberList );
	printf( "NumberList Contents: %f\n", *numberList );
	printf( "NumberList Address: %p\n", numberList + 1 );
	printf( "NumberList Contents: %f\n\n", *(numberList + 1) );
	
	//void * malloc(size_t bytes);
	printf("Pointers and Structure\n");
	ComplexPointers();
	
	printf("Passing Variables \"By Referece\" \n");	
	Test = 13;
	printf("Test is %d\n", Test);
	Change ( &Test );
	printf("Test is now %d\n",Test);

	free(pointer);
	free(numberList);
	return 0;
}

void ComplexPointers()
{
	typedef struct
	{
	    int     x;
	    int     y;
	    int     z;
	} Point;
	
	int i;

	Point *PointList = (Point *) malloc(10*sizeof (Point) );
	Point *WorkPoint;

	PointList[3].x = 5;
	PointList[3].y = 7;
	PointList[3].z = 9;
	
	WorkPoint = PointList + 4;
	WorkPoint->x = 11;
	WorkPoint->y = 13;
	WorkPoint->z = 15;
	
	//for(i=0; i<3; i++){
	printf( "PointList address: %p\n",PointList);
	printf( "PointList contents: %d, %d, %d\n", PointList[3].x, PointList[3].y, PointList[3].z);
	printf(	"WorkPoint address: %p\n", WorkPoint);
	printf(	"WorkPoint contents: %d, %d, %d\n\n",WorkPoint->x, WorkPoint->y, WorkPoint->z);
	//}
	
	free(PointList);


}

void Change(int *Parm)
{	
	*Parm = 42;
}








































