/*
* Program:	HW7_lnr7605.tar 	 Due Date: 12-11-2016
*
* Author:	Lucas Reid 		 Course COMP302-1
*
* Description:  Impliment a mutex into a threaded count.
*		Compare between a mutex and a non-mutex function	
*		write to an output file for both mutex and non-
*			mutex		
*/
// application includes
#include "Thread.h"

// library includes
#include <iostream>		// for cout
#include <sys/time.h>	// for gettimeofday

// use the standard namespace
using namespace std;

// main function
int main( int argc, char **argv )
{
	// create an instance of the thread class
	Thread		Example;

	// get the starting time
	struct timeval	Start;
	gettimeofday( &Start, NULL );

	// first call helloworld sequentially
	//		this doesn't use threads
	cout<<"Hello World Sequentially"<<endl;
	Example.HelloWorldSequential();

	// get the ending time
	struct timeval	End;
	gettimeofday( &End, NULL );

	// output the elapsed time
	cout<<"Sequential Elapsed time: "<<(End.tv_sec - Start.tv_sec)<<" seconds"<<endl;

	// put out some empty lines
	cout<<endl<<endl;

	// get the starting time
	gettimeofday( &Start, NULL );

	// now call it threaded
	//		this will use threads
	cout<<"Hello World Threaded"<<endl;
	Example.HelloWorldThreaded();

	// wait for the threads to complete
	Example.WaitForThreads();

	// get the ending time
	gettimeofday( &End, NULL );

	// output the elapsed time
	cout<<"Threaded Elapsed time: "<<(End.tv_sec - Start.tv_sec)<<" seconds"<<endl;

	Example.newSeq();

	// return finished
	return( 0 );
}
