/*
* Program:	lab14_lnr7605.c	 Due Date: 11-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Mix Parent and children into the same list
*		Understand and use virtual functions
*		Understand and use static data members			
*/
// includes
#include "Faculty.h"
#include "Student.h"

#include <iomanip>
#include <iostream>

// print function
void Print( Person &WorkPerson )
{
    // output name
    cout<<WorkPerson.GetType()<<" ";
    WorkPerson.Print();

    // return finished
    return;
}
// main function
int main( int argc, char **argv )
{
	Base 	Application;
	Application.LogOpen();
	// create a teacher
	Faculty		Teacher( "Dr.", "Fred", "Flinstone", "Akeley", 345 );
	Faculty		Professor( "Dr.", "Homer", "Simpson", "Raub", 999 );

	// create a student
	Student		TeachersPet( "Jane", "Doe", 60.0, 3.75 );
	Student		Nerd( "Bill", "Nye", 75.0, 4.00 );

	
	Print( Teacher );
	Print( Professor );
	Print( TeachersPet );
	Print( Nerd );
	// return finished
	Application.LogClose();
	return( 0 );
}


