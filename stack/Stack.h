#ifndef _STACK_H_
#define _STACK_H_

/* Include headers */
#include "Headers.h"

/* Define Stack Data types */
typedef void * stackDataType;

struct stackStruct{
	struct stackStruct *previous;
	stackDataType dataPointer;
	struct stackStruct *next;
};

/* Definition of stack structure pointer */
typedef struct stackStruct * stackStructPointer;

/* Class for Stack implementation */
class Stack_{
private:
	bool isEmpty( stackStructPointer *top ){
		if( NULL == *top )
			return true;
		return false;
	}

public:
	// Insert data into stack
	#pragma warning( disable : 4996 )
	bool push( stackStructPointer *top, stackDataType data, unsigned char dataLength );

	// Remove data from stack
	stackDataType pop( stackStructPointer *top );
	// Fetch TOP data from stack
	stackDataType peek( stackStructPointer *top );
};

#endif	/* Stack.h */