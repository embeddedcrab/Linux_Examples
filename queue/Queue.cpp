
// include standard headers
#include <stdlib.h>
// include headers
#include "Queue.h"

#if defined DEBUG
	#include <stdio.h>
#endif

_Queue::_Queue(void)
{
	/* Do Nothing */
}


_Queue::~_Queue(void)
{
	/* Do Nothing */
}

/* xQueuePointer createNode ( QueueData data )
 * Description: create a node for queue
 * input: daat to be entered to created node
 * return: address of created node
*/
xQueuePointer _Queue :: createNode ( xQueueData data ) {

	// create a node
	xQueuePointer node;

	// allocate memory to node
	if ( NULL == (node = (xQueuePointer) malloc( sizeof(xQueue) ) ) ) {
		#if defined DEBUG
			printf("%s\n","Cannot create node");
		#endif
		return NULL;
	}

	// put data in created node
	node->data = data;
	node->tail = NULL;

	return node;		// return address of created node
}


/* xQueuePointer createQueue ( unsigned int length ) 
 * Description: create queue with given number of length input, queue fo fixed size
 * input: number of nodes of queue to be created
 * return: 
*/
xQueuePointer _Queue :: createQueue ( unsigned int length ) {

	// create node for starting address
	xQueuePointer node;
	// allocate memory to queue
	if ( NULL == ( node =  ( xQueuePointer ) malloc( sizeof(xQueue) * length ) ) ) {
			#if defined DEBUG
				printf("%s\n","Cannot create Queue");
			#endif
			return NULL;
	}

	return node;
}


/* bool isEmpty ( xQueuePointer *headPointer )
 * Description: check whether Queue is empty or not
 * input: head pointer to queue
 * return true -> if not empty
			false -> if empty
*/
bool _Queue :: isEmpty ( xQueuePointer headPointer ) {

	// check for NULL
	if ( NULL == headPointer )
		return false;
	return true;
}


/* void sendToQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer, xQueueData data ) 
 * 
*/
void _Queue :: sendToQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer, xQueueData data ) {
	
	// temporary node
	xQueuePointer current, node;

	// create new node to add to queue
	if ( NULL == (node = createNode ( data )) ) {
		#if defined DEBUG
			printf("%s\n","cannot add to queue");
		#endif
		return;
	}

	// if queue is empty then add at head position
	if ( !(isEmpty ( *headPointer )) ) {
		#if defined DEBUG
			printf("%s\n","Queue is Empty, putting value at front");
		#endif
		*headPointer = node;
		return;
	}

	else { // go to last position
		// go to position of queue which is pointing to NULL
		current = *headPointer;
		while (current->tail != NULL) {
			current = current->tail;
		}
		//for ( current = *headPointer; current->tail != NULL; current = current->tail );
		// add item to queue
		current->tail = node;
	}

	//update tail of node
	*tailPointer = node;
	
}


/* unsigned int receiveFromQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer ) 
 * Description: receive data from queue and delete that position
 * inpiut: head and tail pointers of queue
 * return value deleted from queue 
*/
xQueueData _Queue :: receiveFromQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer ) {

	// temporary node
	xQueuePointer current;
	// temporary value
	xQueueData value;

	// if queue is empty then add at head position
	if ( !(isEmpty ( *headPointer )) ) {
		#if defined DEBUG
			printf("%s\n","Cannot delete, Queue is Empty");
		#endif
		return (*headPointer)->data;
	}

	// get headPointer position
	current = *headPointer;
	value = (*headPointer)->data;
	// update headPoonter position to next position
	*headPointer = (*headPointer)->tail;

	// free memory of previous head pointer
	free(current);

	// return fetched vaue from queue
	return value;

}


/* unsigned int getPeek ( xQueuePointer *headPointer, xQueuePointer *tailPointer )  
 * Description: fetch head value from queu but dont delete it
 * input: head and tail poineters of queue
 * return: value of peek posiiton
*/
unsigned int _Queue :: getPeek ( xQueuePointer *headPointer, xQueuePointer *tailPointer ) {

	// if queue is empty then add at head position
	if ( !(isEmpty ( *headPointer )) ) {
		#if defined DEBUG
			printf("%s\n","Queue is Empty");
		#endif
	}

	return (*headPointer)->data;
}


/* void display ( xQueuePointer *headPointer ) 
 * Description: display contents of queue
 * input: head pointer to queue first position
 * return: void
*/
void _Queue :: display ( xQueuePointer *headPointer ) {

	// temporary node
	xQueuePointer current;

	// if queue is empty then add at head position
	if ( !(isEmpty ( *headPointer )) ) {
		#if defined DEBUG
			printf("%s\n","Queue is Empty");
		#endif
			return;
	}

	// point to first position of queue, and diaplay contents
	current = (*headPointer);
	do {
		#if defined DEBUG
			printf("%u\t", current->data);
		#endif
		current = current->tail;
	} while ( current != NULL );

}


/* void reset ( xQueuePointer *headPointer, xQueuePointer *tailPointer )  
 * Description: reset queue values to Zero (0)
 * input: head and tail pointers to queue
 * return: void
*/
void _Queue :: reset ( xQueuePointer *headPointer, xQueuePointer *tailPointer ) {

	// temporary variable
	xQueuePointer current;

	// get first node using headPoointer and make its data to Zero then proceed to following nocde till last node
	current = *headPointer;
	while (current != NULL) {
		current->data = 0;
		current = current->tail;
	}

}


/* void deleteQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer )  
 * Description: delete Queue from memory
 * input: head and tail pointers of queue
 * reuturn: void
*/
void _Queue :: deleteQueue ( xQueuePointer *headPointer, xQueuePointer *tailPointer ) {

	// temporary variable
	xQueuePointer current;

	// get current position using headPointer and make headPointer points to next position then delete memory and so on.. 
	// till lat node i.e, NULL 
	// or can consider TAILPOINTER also (depends on your wish)
	current = *headPointer;
	while ((*headPointer) != NULL) {
		*headPointer = (*headPointer)->tail;
		free(current);
		current = *headPointer;
	}

	#if defined DEBUG
		printf("%s\n", "Queue deleted from memory");
	#endif

}