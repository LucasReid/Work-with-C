// includes
#include "Faculty.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor
Faculty::Faculty( string NewSalutation, string NewFirstName, string NewLastName, string NewOfficeBuilding, int NewOfficeNumber ) : Person( NewFirstName, NewLastName )
{
	// console output
	Output( "In FACULTY constructor" );

	// intialize the data members
	Salutation 		= NewSalutation;
	OfficeBuilding	= NewOfficeBuilding;
	OfficeNumber	= NewOfficeNumber;
}

// destructor
Faculty::~Faculty()
{

}
string Faculty::GetType(){
	
	return( "Faculty" );
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
