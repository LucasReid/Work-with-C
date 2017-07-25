#include "Base.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Base::Base(){

}

Base::~Base(){}

void Base::ConsoleOutput(string Message){
	time_t now = time(0);
	tm 	*lt = localtime(&now);
	
	cout<<"["<<lt->tm_year+1900
	<<"-"<<setfill('0')<<setw(2)<<lt->tm_mon+1
	<<"-"<<setfill('0')<<setw(2)<<lt->tm_mday
        <<"-"<<setfill('0')<<setw(2)<<lt->tm_hour
        <<":"<<setfill('0')<<setw(2)<<lt->tm_min
        <<":"<<setfill('0')<<setw(2)<<lt->tm_sec
        <<"]"
        <<Message<<endl;
        
	return;
}
