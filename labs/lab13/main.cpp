/*
* Program:	lab13_lnr7605.c	 Due Date: 11-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Understand inheritance
*		Identify when to use inheritance
*		Use inheritance to provide common program routines			
*/
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "iostream"

using namespace std;

int main(int argc, char** argv){
	Faculty 	teacher("Dr.", "Fred", "Flinstone","Akeley", 345);
	
	Student		teachersPet("Jane","Doe",60.0, 3.75);
	
	teacher.Print();
	teachersPet.Print();
	
	return 0;
}



