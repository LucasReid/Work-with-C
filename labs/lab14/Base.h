#ifndef BASE_H_
#define BASE_H_

// includes
#include <iostream>
#include <string>
using namespace std;

// base class
class Base {
	// constructors and estructors
	private:
		static ofstream 	LogFile;
		
	public:
		Base();
		virtual ~Base();

	// console output
	public:
		void LogOpen();
		void LogClose();
		void Output(string Message);
			
};

#endif /* BASE_H_ */
