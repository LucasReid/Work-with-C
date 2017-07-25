// includes
#include "Person.h"
#include <iostream>
using namespace std;

// constructor
Person::Person( string NewFirstName, string NewLastName )
{
	// console output
	Output( "In PERSON constructor" );

	// initialize data members
	FirstName 	= 	NewFirstName;
	LastName	=	NewLastName;
}

// destructor
Person::~Person()
{

}

// print a person's name
void Person::Print()
{
	// ouput the name
	cout<<"Name: "<<LastName<<", "<<FirstName<<endl;

	// return finshed
	return;
}

