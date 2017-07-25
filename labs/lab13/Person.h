#ifndef PERSON_H_
#define PERSON_H_
#include "Base.h"

#include <string>
using namespace std;

class Person : public Base{

	protected:
		string FirstName;
		string LastName;
	public:
		Person(string NewFirstName, string NewLastName);
		virtual ~Person();
	public:
	void Print();	
		

};
#endif
