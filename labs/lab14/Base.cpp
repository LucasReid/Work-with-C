// includes
#include "Base.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;
ofstream Base::LogFile;

// constructor
Base::Base()
{
	// console output
	Output( "In BASE constructor" );
}

// destuctor
Base::~Base()
{

}
void Base::LogOpen(){
	if(!LogFile.is_open())
		LogFile.open( "LogFile.txt" );
	
	return;
}
void Base::LogClose(){
	if(LogFile.is_open())
		LogFile.close();
	return;
}

void Base::Output( string Message )
{
    // get the current time
    time_t          now =   time(0);
    tm              *lt =   localtime(&now);
    ostringstream   DateTime;

    // output the time and date stamp
    DateTime<<"["
            <<lt->tm_year+1900
            <<"-"<<setfill('0')<<setw(2)<<lt->tm_mon+1
            <<"-"<<setfill('0')<<setw(2)<<lt->tm_mday
            <<"-"<<setfill('0')<<setw(2)<<lt->tm_hour
            <<":"<<setfill('0')<<setw(2)<<lt->tm_min
            <<":"<<setfill('0')<<setw(2)<<lt->tm_sec
            <<"]";

    // output message
    if ( LogFile.is_open() )
        LogFile<<DateTime.str()<<" "<<Message<<endl<<flush;
    

    // return finished
    return;
} 

































