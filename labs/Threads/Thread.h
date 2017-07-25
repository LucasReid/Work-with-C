#ifndef THREAD_H_
#define THREAD_H_

// library include
#include <vector>
#include <thread>

// use the standard namespace
using namespace std;

// thread class definition
class Thread {
	// data members
	private:
		std::vector<std::thread>		ThreadList;

	// constructors and destructors
	public:
		Thread();
		virtual ~Thread();

	// methods
	private:
		// this function is used to create and
		//		start a thread
		void	CreateThread( int ThreadNumber );

		// this is the routing we will be
		//		running in parallel
		void	HelloWorld( int Counter );
		
		void 	HelloWorldSeq(int counter);

	public:
		// this calls helloworld 5 times sequentially
		void	HelloWorldSequential();

		// this calls hellowworld 5 times in parallel
		void	HelloWorldThreaded();

		// this method waits for all of the threads
		//		to complete
		void	WaitForThreads();
		
		void 	newSeq();
		
	
};

#endif /* THREAD_H_ */
