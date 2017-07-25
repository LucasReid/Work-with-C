#include "stringLab.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

stringLab::stringLab(){
}
stringLab::~stringLab(){}

void stringLab::testStrings(){

	string lastName;
	string wholeName;
	
	
	lastName = "Schwartzenegger";
	string firstName("Arnold");
	
	wholeName = lastName+", "+firstName;
	int position = wholeName.find( "egg" );
	
	cout<<wholeName.substr(10, 3)<<endl;
	cout<<"egg is located at position "<<position<<endl;
	
	wholeName.erase( position, 3);
	wholeName.insert(position, "bacon");
	cout<<wholeName<<endl;
	
	cout<<wholeName.length()<<endl;
	for( int i=0; i<5; i++){
		wholeName += "extra";
		cout<<"'"<<wholeName<<"' is "<<wholeName.length()<<" characters long"<<endl;
	}
	
	return;
}
void stringLab::userInput(){
	string text; 
	
	/*cout<<"Enter Text: ";
	cin>>text;
	cout<<"Text: '"<<text<<"'"<<endl;
	*/
	do{
	cout<<"Enter a line of text: ";
	getline( cin, text);
	cout<<"Text: '"<<text<<"'"<<endl;
	
	}while(!text.empty());
	return;
}
void stringLab::stringStreams(){
	ostringstream outString;
	double	PI= 3.14159265;
	long	meaningOfLife = 42;
	
	string 		data ="45 64 99";
	istringstream	inString( data );
	int 		number;
	
	outString<<PI<<" "<<meaningOfLife;
	cout<<outString.str()<<endl;
	
	for(int i=1; i<4; i++){
	inString>>number;
	cout<<"Number "<<i<<" is: "<<number<<endl;
	}
	
	return;
}




















