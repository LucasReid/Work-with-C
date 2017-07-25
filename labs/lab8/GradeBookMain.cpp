/*quiz
* Program:	Lab8_lnr7605.c	 Due Date: 10-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Get user input using cin
*		Input data from a file using ifstream	
*		Output data to a file using ofstream	
*		Use iomanip featurs to format output	
*		Create run-time variables (pointers) in C++ using new	
*										
*/
#include "GradeBook.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	GradeBook	GB("hw5Gradebook.txt");
	GB.output();
	return (0);
}


