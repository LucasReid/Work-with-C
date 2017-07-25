/*
 * Student.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

// includes
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor
Student::Student( string NewFirstName, string NewLastName, double NewCreditsEarned, double NewGPA ) : Person( NewFirstName, NewLastName)
{
	
	// intialize the data members
	CreditsEarned 	= NewCreditsEarned;
	GPA 			= NewGPA;
	
	ConsoleOutput("In STUDENT constructor");
}

// destructor
Student::~Student()
{

}

// print method
void Student::Print()
{
	
	// ouput the name
	//cout<<"Name: "<<LastName<<", "<<FirstName<<endl;
	Person::Print();
	cout<<"   Credits Earned: "<<CreditsEarned<<endl;
	cout<<"   GPA: "<<GPA<<endl;

	// return finished
	return;
}

