// application includes
#include "Thread.h"

// library includes
//		for cout
#include <iostream>
//		for sleep
#include <unistd.h>

#include <fstream>
#include <mutex>

// use the standard namespace
using namespace std;

// constructor
Thread::Thread()
{

}

// destructor
Thread::~Thread()
{

}

// hello world method
void Thread::HelloWorld( int Counter )
{
	ofstream outFile("noMutex.txt");
	
	// do this five times
	for( int i=0; i<5; i++ )
	{
		// output the message
		outFile<<"  Hello World #"<<i<<" from "<<Counter<<endl;
		
		// sleep for one seconds
		//		this is just make the time something
		//		significant
	}
	outFile.close();
	// return finished
	return;
}
void Thread::HelloWorldSeq(int Counter){
	mutex threadMutex;
	ofstream outFile("Mutex.txt");
	int total = 0;
	threadMutex.lock();
	for(int i=0; i<5; i++)
	{
		total +=10;
		outFile<<"  Hello World #"<<i<<" from "<<Counter<<endl;
	}
	outFile<<total<<endl;
	threadMutex.unlock();
	//add a total -increment by 10 each time through the for loop
	//Change cout -> output to a file
	//"noMutex.txt" = output file
	//add a mutex Protect the call to output and counter
	//final version goes to "Mutex.txt"
	//mutex threadMutex;
	//threadMutex.lock();
	outFile.close();	
	return;
}
void Thread::newSeq(){
	for(int i=0; i<5; i++)
	HelloWorldSeq(i);
	
	return;
}
// call helloworld 5 times sequentially
void Thread::HelloWorldSequential()
{
	// loop five times
	for( int i=0; i<5; i++ )
		// call the function
		HelloWorld( i );

	// return finished
	return;
}

// call helloworld threaded
void Thread::HelloWorldThreaded()
{
	// loop five times
	for( int i=0; i<5; i++ )
		// create a thread that runs helloworld
		CreateThread( i );

    // return finished
	return;
}

// start a helloworld thread
void Thread::CreateThread( int Counter )
{
	// create a new thread
	//		that runs HelloWorld
	thread		WorkThread( &Thread::HelloWorld, this, Counter );

	// add it to the list
	//		need to keep a list so that you can
	//		check that all threads are complete
	//		at somepoint in your program
	//
	// the move function needs to be used. it has to
	//		do limiting the creation of temporary
	//		objects to increase the efficiency of
	//		C++ programs. if you want to read more
	//		about it (I am not sure that I quite get
	//		the whole thing yet) see this link:
	//		http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
	//
	ThreadList.push_back( move( WorkThread ) );

	// return finished
	return;
}

// check that all threads are done
void Thread::WaitForThreads()
{
	// run through the list
	for( auto& WorkThread : ThreadList )
		// join waits until the thread is done
		//		if the thread is already complete
		//		join returns right away
		WorkThread.join();

	// return finished
	return;
}






























