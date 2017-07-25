#ifndef STUDENT_H_
#define STUDENT_H_

// inlcudes
#include "Person.h"

// student class
class Student : public Person {
	// data members
	private:
		double	CreditsEarned;
		double	GPA;

	// constructors and destructor
	public:
		Student( string NewFirstName, string NewLastName, double CreditsEarned, double GPA );
		virtual ~Student();

	// methods
	public:
		void Print();
		void Print2();
		string GetType();
};

#endif /* STUDENT_H_ */
