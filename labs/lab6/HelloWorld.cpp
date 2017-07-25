#include "HelloWorld.h"
#include <iostream>
using namespace std;

HelloWorld::HelloWorld(){
	
	cout<<"In the constructor"<<endl;
	
}
HelloWorld::~HelloWorld(){

	cout<<"In the destructor"<<endl;
	
}

void HelloWorld::printMessage(){
	cout<<"Hello World 2.0!"<<endl;
}
