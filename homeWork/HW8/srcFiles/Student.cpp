// includes
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;

// constructor
Student::Student( string NewFirstName, string NewLastName,  double NewCreditsEarned, double NewGPA ) : Person( NewFirstName, NewLastName )
{
	// console output
	Output( "In STUDENT constructor" );

	// intialize the data members
	CreditsEarned 	= NewCreditsEarned;
	GPA 			= NewGPA;
}

// destructor
Student::~Student()
{

}
string Student::GetType(){
	
	return( "Student" );
}
// print method
void Student::Print2()
{
	// ouput the name
	cout<<"Name: "<<LastName<<", "<<FirstName<<endl;
	cout<<"   Credits Earned: "<<CreditsEarned<<endl;
	cout<<"   GPA: "<<GPA<<endl;

	// return finished
	return;
}

// print method
void Student::Print()
{
	// print the name
	Person::Print();
	cout<<"   Credits Earned: "<<CreditsEarned<<endl;
	cout<<"   GPA: "<<GPA<<endl;

	// return finished
	return;
}

