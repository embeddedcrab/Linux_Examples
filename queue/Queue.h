
#ifndef __QUEUE_H_
#define __QUEUE_H_

// define to use printing, uncommennt to debug
//#define DEBUG

// Queue node daat type
typedef unsigned int xQueueData;

// definition of queue
struct queueNode {

	xQueueData data;
	queueNode *tail;
};

// another names for queue and queue pointers
typedef queueNode xQueue;
typedef xQueue * xQueuePointer;


// API class for Queue
class _Queue {
	// private functions
	private:
		// create node
		xQueuePointer createNode ( xQueueData data );
		// check empty condition of queue
		bool isEmpty ( xQueuePointer headPointer );

	// public functions of Queue
	public:
		_Queue(void);	// constructor
		~_Queue(void);	// deconstructor

		// create queue
		xQueuePointer createQueue ( unsigned int length );

		// send data to queue, always send at tail position
		void sendToQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer, xQueueData data );
		// receive data from queue, always from front position
		xQueueData receiveFromQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer );

		// fetch peek value
		unsigned int getPeek ( xQueuePointer *headPointer, xQueuePointer *tailPointer );

		// display queue contents
		void display ( xQueuePointer *headPointer );

		// make all data fields to NULL
		void reset ( xQueuePointer *headPointer, xQueuePointer *tailPointer );
		// delete queue, deconstructor can also be used
		void deleteQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer );

};// class Queue ends


#endif	/* Queue.h */