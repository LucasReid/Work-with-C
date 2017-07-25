/*
 * Faculty.h
 *
 *  Created on: Apr 6, 2013
 *      Author: phuegler
 */

#ifndef FACULTY_H_
#define FACULTY_H_
#include "Person.h"

// faculty class
class Faculty : public Person {
	// data members
	private:
		string	Salutation;
		string	OfficeBuilding;
		int		OfficeNumber;

	// constructors and destructor
	public:
		Faculty( string NewSalutation, string NewFirstName, string NewLastName, string NewOfficeBuilding, int NewOfficeNumber );
		virtual ~Faculty();

	// methods
	public:
		void Print();
};

#endif /* FACULTY_H_ */
