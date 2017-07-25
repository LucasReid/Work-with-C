/*
 * Faculty.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

// includes
#include "Faculty.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor
Faculty::Faculty( string NewSalutation, string NewFirstName, string NewLastName, string NewOfficeBuilding, int NewOfficeNumber ) : Person(NewFirstName, NewLastName)
{
	// intialize the data members
	Salutation 		= NewSalutation;
	OfficeBuilding	= NewOfficeBuilding;
	OfficeNumber	= NewOfficeNumber;
	
	ConsoleOutput("In FACULTY constructor");
}

// destructor
Faculty::~Faculty()
{

}

// print method
void Faculty::Print()
{
	// ouput the name
	cout<<"Name: "<<Salutation<<" "<<LastName<<", "<<FirstName<<endl;
	cout<<"   Office: "<<OfficeNumber<<" "<<OfficeBuilding<<endl;

	// return finished
	return;
}
