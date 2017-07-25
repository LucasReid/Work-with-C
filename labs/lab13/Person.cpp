#include "Person.h"
#include <iostream>
#include <iomanip>
using namespace std;

Person::Person(string NewFirstName, string NewLastName){

	FirstName = NewFirstName;
	LastName = NewLastName;

}
Person::~Person(){}

void Person::Print(){

	cout<<"Name: "<<LastName<<", "<<FirstName<<endl;
	
	return;
}

