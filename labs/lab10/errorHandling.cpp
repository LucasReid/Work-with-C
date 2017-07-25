#include "errorHandling.h"
#include <iostream>
#include <stdexcept>
#include <ifstream>
using namespace std;

errorHandling::errorHandling(){

}
errorHandling::~errorHandling(){}

void errorHandling::errorTesting(){
	try{
		int Number;
		
		cout<<"Enter a number: ";
		cin>>Number;
		if( Number > 1000 )
		{
			throw( (double) 3.14159265 );
		}
		if( Number>100)
		{
			int Error = 42;
			throw( Error );
		}
		
		if( Number <0)
		{
			throw( (string) "Negative Number");
		}
		
		cout<<"The number is: "<<Number<<endl;	
	}
	catch( string &Message )
	{
		cerr<<"Exception Thrown: "<<Message<<endl;
	}
	catch( int NumberErr ){
		cerr<<"An integer exception has occurred: "<<NumberErr;
	}
	catch( ... )
	{
		cerr<<"An exception has occurred"<<endl;
	}
	
	return;
}

void errorHandling::exceptionTesting(){
	try{
		ifstream InFile("Error.txt");
	
	if(!InFile)
	{
		runtime_error myException( "Error opening file");
		throw (myException);
	}
	int *list = new int[-1];
	}
	catch(exception &e)
	{
		cerr<<"Exception occured: "<<e.what()<<endl;
	}
	
	
	return;
}





















