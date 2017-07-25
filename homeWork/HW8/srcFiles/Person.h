#ifndef PERSON_H_
#define PERSON_H_

// includes
#include "Base.h"
#include <string>
using namespace std;

// person class
class Person : public Base {
	// data members
	protected:
		string	FirstName;
		string	LastName;

	// constructors and destructor
	public:
		Person( string NewFirstName, string NewLastName );
		virtual ~Person();


	// methods
	public:
		void Print();
		virtual string GetType() =0;
};

#endif /* PERSON_H_ */
