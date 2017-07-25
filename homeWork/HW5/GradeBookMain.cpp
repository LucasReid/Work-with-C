/*quiz
* Program:	HW5_lnr7605.c	 Due Date: 11-09-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Increased Functionality of the Gradebook class
*		Displays output for individual students which include:	
*			-Course name
*			-Grade weights
*			-Number of quizes & tests
*			-Student ID & Student name
*			-Quiz & Test scores							
*/
#include "GradeBook.h"
#include <iostream>


using namespace std;

int main(int argc, char** argv){
	GradeBook	GB("hw5Gradebook.txt");
	GB.printClassStats();
	GB.printStudentGrades();
	return (0);
}


