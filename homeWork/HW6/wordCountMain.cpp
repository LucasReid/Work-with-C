//sudoCode
#include "wordCount.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main(int argv, char** argc){

	string inFileName;
	
	try {
		cout<<"Enter the File you want to run through Word Count\n\t please include the .txt";
		cin>>inFileName;
		wordCount   WC(inFileName);
		//WC.outputMap();
		
	}
	catch(exception &e){
		cerr<<"Exception Occured:"<<e.what()<<endl;
	}
	catch(...)
	{
		cerr<<"Something Unexpected happened! Please restart program"<<endl;
	}
	return 0;
}


