
/* Include headers */
#include "threads.h"


/********************* Member Function of class Threads_ **************************/

/* Function for thread creation */
int8_t Threads_ :: create( pthread_attr_t *attr ){
	
	/* Local variable to store returned value */
	int ret;
	/* Create thread */
	ret = pthread_create( &threadID, attr, Threads_::staticEntryPoint, this );

	return ret;
}


/* Function to join thread, it will return store data returned from pthread_exit() in value_ptr */
void Threads_ :: join( void **value_ptr ){
	/* Call join function */
	pthread_join( threadID, value_ptr);
}


/* Get Thread ID */
pthread_t Threads_ :: self( void ){
	/* return thread ID */
	return threadID;
}


/* Detach a thread */
int8_t Threads_ :: detach( pthread_t thread_id ){
	/* Local variable to store result */
	int8_t ret;
	/* Detach thread */
	ret = pthread_detach( thread_id );

	return ret;
}


/* Compare two threads on basis of IDs */
int8_t Threads_ :: equal(pthread_t thread_id){
	/* Local variable to store result */
	int8_t ret;
	/* Compare two threads */
	ret = pthread_equal( threadID, thread_id );

	return ret;
}



/********************* Thread Synchronization functions **************************/

/* Initialize Mutex */
int8_t Mutex_ :: initMutex( pthread_mutex_t *mutex, const pthread_mutexattr_t *attr ){
	/* Local variable */
	int8_t ret;
	ret = pthread_mutex_init( mutex, attr );

	return ret;
}


/* Lock Mutex */
int8_t Mutex_ :: lockMutex( pthread_mutex_t *mutex ){
	/* Local variable */
	int8_t ret;
	/* lock mutex */
	ret =  pthread_mutex_lock( mutex );

	return ret;
}


/* Try locking Mutex */
int8_t Mutex_ :: trylockMutex( pthread_mutex_t *mutex ){
	/* Local variable */
	int8_t ret;
	/* lock mutex */
	ret =  pthread_mutex_trylock( mutex );

	return ret;
}


/* Unlock Mutex */
int8_t Mutex_ :: unlockMutex( pthread_mutex_t *mutex ){
	/* Local variable */
	int8_t ret;
	/* lock mutex */
	ret =  pthread_mutex_unlock( mutex );

	return ret;
}


/* Destroy Mutex */
int8_t Mutex_ :: destroyMutex( pthread_mutex_t *mutex ){
	/* Local variable */
	int8_t ret;
	/* lock mutex */
	ret = pthread_mutex_destroy( mutex );

	return ret;
}


/****************************************************************************************************/
