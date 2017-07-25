/*
* Program:	lab4_lnr7605.c	 Due Date: 09-25-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Use #include to include code from another file.
*		Use #define to make code easier to read	
*		Use #define to define macros
*		Use #ifdef and #ifndef to conditionally compile code
*		
*/

#include <stdio.h>
#define PI 3.14159265
#define AreaCircle (r) ( PI *r *r)
#define Debug

int main(int argc, char** argv){
	int Radius;
	double Area;

	printf("Enter a radius:");
	scanf("%d", &Radius);
	
	#ifdef Debug
		printf("The radius entered was %d\n", Radius);
	#endif
	
	//double Area = PI * Radius *Radius;

	Area = AreaCircle (Radius);
	printf("\nThe Area is: %f\n", Area);

	
	return 0;
}





















































