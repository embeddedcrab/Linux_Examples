/* Include headers */
#include "Headers.h"
#include "Stack.h"


bool Stack_::push( stackStructPointer *top, stackDataType data, unsigned char dataLength ){
	/* Add data into List and increment TOP */
	// Allocate memory for data
	stackDataType stackData = (stackDataType)malloc( sizeof(stackDataType) * dataLength );
	if( NULL == stackData ){
		return false;
	}

	// Copy data into StackData
	strcpy((char *)stackData, (const char *)data);

	// Create New node for double linked list
	stackStructPointer node = ( stackStructPointer )malloc( sizeof(stackStruct) );
	// Check whether node is creted or not
	if( NULL == node ){
		return false;
	}
	// Initialize node
	node->previous = NULL;
	node->dataPointer = stackData;
	node->next = NULL;

	// Check whether stack is empty or not
	if( isEmpty( top ) ){
		*top = node;
		return true;
	}

	// Add item to list
	node->previous = (*top);
	// Make top point to new node
	*top = node;

	return true;
}

stackDataType Stack_::pop( stackStructPointer *top ){
	// Check whether stack is empty or not
	if( isEmpty(top) ){
		cout<< "Stack is Empty" << endl;
		return NULL;
	}
	
	// Taking a local variable to store data
	//unsigned char a = strlen((char *)(*top)->dataPointer);
	stackDataType data = (stackDataType) malloc( sizeof((*top)->dataPointer) * (strlen((char *)(*top)->dataPointer)) );
	
	// Copy data pointed by temp into data
	strcpy( (char *)data, (const char *)(*top)->dataPointer );

	// Taking temporary node
	stackStructPointer temp = *top;

	if( temp->previous != NULL ){
		// Create link with previous node
		temp->previous->next = NULL;
		*top = temp->previous;
	}
	else{
		*top = NULL;
	}

	// Free memory allocated for node and data pointer of that node
	free(temp->dataPointer);
	free(temp);

	return data;
}


stackDataType Stack_::peek( stackStructPointer *top ){
	// Fetch TOP data from stack
	if( !isEmpty(top) )
		return (*top)->dataPointer;
	cout<< "Stack Empty ! ";
	return NULL;
}