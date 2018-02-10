#ifndef _LIST_H_
#define _LIST_H_

/* Include Headers */
#include "Headers.h"


/* Define Data type for list */
typedef char * ListDataType;

/* Defining structure for list */
struct ListStructure{
	ListDataType dataPointer;
	struct ListStructure *next;
};

/* Define type for pointer for ListStructure */
typedef ListStructure * ListStructurePointer;

/* Class definition for LIST */
class List_{
private:
	bool isEmpty( ListStructurePointer head ){
		if( NULL == head )
			return 1;
		return 0;
	}

public:
	static unsigned int length( ListStructurePointer *head );

	#pragma warning(disable : 4996)
	bool addItem( ListStructurePointer * head, ListDataType data, unsigned int dataLength, bool position=false );
	bool removeItem( ListStructurePointer * head, bool position=false );

	void display( ListStructurePointer * head );
	void diplayReverse( ListStructurePointer * head );

	bool deleteList( ListStructurePointer *head );

	bool reverse( ListStructurePointer *head );

};

#endif	/* List.h */