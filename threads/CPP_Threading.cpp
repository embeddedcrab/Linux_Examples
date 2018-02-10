/* Including required Libraries. */
#include <iostream>
#include <stdio.h>
#include <pthread.h>


using namespace std;
 

/* Class for threads. */
class DisplayThreads_
{
private:
	/* Thread Variables. */
	pthread_t Display_Thread;

	/* Thread Functions. */
	//Display Threads.
	static void * StaticDisplayThreadEntryPoint(void *Arg);	//Pointing to Thread Body.
	void DisplayThreadEntryPoint();	//Contains Thread Body, Functionality of thread.

public:
	/* Function to wait for thread to finish. */
        void waitForThread( void ){
                pthread_join( Display_Thread, NULL );
        }

	void DisplayThread();	//Contains Thread Creation
};

///////////////////////////////////////////////////////////////////////////////////


int main( int argc, char ** argv )
{
/* Declaring a reference. */
DisplayThreads_ Display;

	/* Call function to create thread. */
	Display.DisplayThread();
	
	/* Call join to wait for thread. */
	Display.waitForThread();
	
	cout << endl << "Thread Demo Completed" << endl;

return 0;
}

///////////////////////////////////////////////////////////////////////////////


/* Display Thread Functions. */
void DisplayThreads_::DisplayThread()
{
// Local Variable
int Thread_check;

	/* Create thread. */
	Thread_check = pthread_create(&Display_Thread, NULL, DisplayThreads_::StaticDisplayThreadEntryPoint, this);
	
	/* If treu then thread creation failed. */
	if( Thread_check )
	{
		cout<< "Error : Unable to Create Display Thread..................!! " << endl;
		perror("Thread Creation Failed : ");
		exit(-1);
	}

	cout << "Thread Created Successfully !" << endl;
}

/* Function to call the thread execution function,
	Works as a wrapper to call main execution function. */
void * DisplayThreads_::StaticDisplayThreadEntryPoint(void * Arg)
{
	((DisplayThreads_ *) Arg)->DisplayThreadEntryPoint();
    	return NULL;
}

/* Function to execute thread functionality */
void DisplayThreads_::DisplayThreadEntryPoint()
{
// Local Variables

	// Functionality of Thread or Main thread execution function
	cout << "Hello World, Thread Execution starts from here !!" << endl;

// Exit from thread, can return some value also (if required).
pthread_exit(NULL);
}

/* END. */
