

#include <iostream>
#include <conio.h>
#include "Queue.h"

using namespace std;

int main ( void ) {

	// create head and tail for queue
	xQueuePointer head = NULL, tail = NULL;

	// create queue object
	_Queue queue;

	cout << "Size of queue object is " << sizeof(queue) << endl;

	queue.sendToQueue ( &head, &tail, 10 );
	queue.sendToQueue ( &head, &tail, 20 );
	queue.sendToQueue ( &head, &tail, 10 );
	queue.sendToQueue ( &head, &tail, 10 );
	queue.sendToQueue ( &head, &tail, 20 );
	queue.sendToQueue ( &head, &tail, 30 );
	queue.sendToQueue ( &head, &tail, 40 );
	queue.sendToQueue ( &head, &tail, 50 );

	cout << "Queue contains : " << endl;
	queue.display ( &head );
	getchar();

	cout << "data from queue is : " << queue.receiveFromQueue( &head, &tail) << endl;
	getchar();

	cout << "peek data from queue is : " << queue.getPeek( &head, &tail) << endl;
	getchar();

	queue.reset( &head, &tail );
	cout << "Queue after reset is : " << endl;
	queue.display ( &head );
	getchar();

	cout << "Deleting Queue.." << endl;
	queue.deleteQueue ( &head, &tail );
	getchar();

	return 0;
}



