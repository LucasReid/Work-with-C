/*
* Program:	lab6_lnr7605.c	 Due Date: 10-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Begining of C++ course work Lab 6 incorporates
*			creating a C++ project
*			creating a cimple C++ program
*			Understanding the basic structure of C++ classes
*			Adding classes to a C++ project
*			Output to the console using cout
*		
*/
#include <iostream>
#include "HelloWorld.h"
using namespace std;

int main(int argc, char **argv)
{
	HelloWorld msgClass;
	msgClass.printMessage();
	//cout << "Hello World" << endl;
	return(0);
}
