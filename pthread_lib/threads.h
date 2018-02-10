#ifndef _THREADS_H_
#define _THREAD_H_

/* Include thread library */
extern "C"{
	#include <pthread.h>
}

#include "stdint.h"

class Threads_{

	private:
		pthread_t threadID;	/**< Thread ID */
		void *threadArg;	/**< Thread Argument which will be passed to thread body function */
		
		/* Function pointer to store address of function which will contain execution part */
		void *( * threadFunctionPointer )( void * );

		/* Function which will call execute function internally */
		static void *staticEntryPoint( void *arg ){
			/* Call execute function from here */
			( (Threads_ *) arg)->execute();

			return NULL;
		}

		/* This function will execute the main thread execution function,
			which contain main thread body.
		*/
		void execute( void ){
			threadFunctionPointer( threadArg );
		}

	public:
		/****************** Constructor and Destructor *****************/
		Threads_( void *(*start_routine) (void *), void *arg ){
			threadFunctionPointer = start_routine;
			threadArg = arg;
		}

		~Threads_(){
			/* Release memory */
		}

		/******************* Data Members *********************/


		/****************** Member functions *****************/
		/* Function for thread creation */
		int8_t create( pthread_attr_t *attr );

		/* Function to join thread, it wiil return store data returned from pthread_exit() in value_ptr */
		void join( void **value_ptr );
		
		/* Get Thread ID */
		pthread_t self( void );

		/* Detach a thread */
		int8_t detach( pthread_t thread_id );
		
		/* Compare two threads on basis of IDs */
		int8_t equal(pthread_t thread_id);

};



class Mutex_{
	private:
		/* EMPTY */
	public:
		/****************** Constructor and Destructor *****************/


		/***************** Thread Synchronization functions ****************/
		/* Initialize Mutex */
		int8_t initMutex( pthread_mutex_t *mutex, const pthread_mutexattr_t *attr );

		/* Lock Mutex */
		int8_t lockMutex( pthread_mutex_t *mutex );

		/* Try locking Mutex */
		int8_t trylockMutex( pthread_mutex_t *mutex );

		/* Unlock Mutex */
		int8_t unlockMutex( pthread_mutex_t *mutex );

		/* Destroy Mutex */
		int8_t destroyMutex( pthread_mutex_t *mutex );

};



#endif	/* threads.h */