/* Include standard libraries */
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

using namespace std;

/* Include libraries */
#include "threads.h"

/* Mutex Variable for thread synchronization */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct{
	void *ptr;
	unsigned int val;
}userStruct;


/* Function to be passed for thread execution */
void * printFunction( void *arg );


int main( void )
{
	/* Local Variables */
	int8_t ret;
	void * ptr;
	char var[] = "HEMANT SHARMA";

	/* Local Structure to be passed as an argument in thread body function */
	userStruct val;
	val.ptr = var;
	val.val = 10;

	/* Create object of Threads_ class*/
	Threads_ * thread = new Threads_( printFunction, (userStruct *)&val );

	/* Create thread */
	ret = thread->create( NULL ); 
	if( ret ){
		printf("%s", "Thread Creation Failed\n");
		perror("Error : ");
		return 1;
	}

	/* Join thread */
	thread->join( &ptr);
	printf("Value returned from thread is %s\n", (const char *)ptr);
	
	/* Size of class */
	cout<< "Size of class is : " << sizeof(Threads_) << endl;

	/* Get thread ID */
	printf("Thread ID of thread is : %ld\n", thread->self());

	/* HOLD to see output */
	getchar();

return 0;
}


/*-------------------------- END ------------------------------------*/


/* Function to be passed for execution */
void * printFunction( void *arg ){

	cout<< "Thread Started.."<< endl;
	/* Fixed Operation */
	printf("1st Argument of structure is %s\n", ((userStruct *)arg)->ptr);

	printf("2nd Argument of structure is %u\n", ((userStruct *)arg)->val);

	cout<< "Thread Ended..!"<< endl;

	pthread_exit("SUCCESS");
return NULL;
}
