/*
* Program:	lab15_lnr7605.c	 Due Date: 11-30-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:	Change the C++ dialect to use
*		Use auto to declare variables
*		Use nullptr, a better version of NULL	
*		Use the foreach construct of the for statement	
*		Use smart pointers	
*/
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>


using namespace std;

int main(int argc, char** argv){

	int *Pointer = nullptr;
	Pointer = new int;
	(*Pointer) = 10;
	cout<<*Pointer<<endl;
	delete Pointer;
	
	unique_ptr<int> 	SmartPointer( new int);
	(*SmartPointer) = 42;
	cout<<*SmartPointer<<endl;

	vector<int>Numbers;
	srand(13);
	Numbers.push_back(rand());
	
	auto Begin = 	Numbers.begin();
	auto End   =	Numbers.end();
	vector<int>::iterator Current = Current;
	
	for(Current = Begin; Current<End; Current++)
		cout<<(*Current)<<endl;

	for(auto Item : Numbers)
		cout<<Item<<endl;


	return 0;	
}


































