/* Include Headers */
#include "List.h"

unsigned int List_::length( ListStructurePointer *head ){
	register unsigned int i = 0;
	ListStructurePointer temp = *head;
	for( ; temp!=NULL; temp=temp->next, ++i );

	return i;
}

bool List_::addItem( ListStructurePointer * head, ListDataType data, unsigned int dataLength, bool position ){
	// Allocate memory for data
	ListDataType dataInserted = (ListDataType) malloc(sizeof(ListDataType) * dataLength);
	if(NULL == dataInserted){
		// Cannot allocate memory for new node
		return 1;
	}
		
	// Copy data into datainserted
	strcpy( dataInserted, data );
	
	// Taking a new node and allocating memory for it
	ListStructurePointer newNode = (ListStructurePointer) malloc(sizeof(ListStructure));	// or can use new also
	// Point newNode data pointer to data
	newNode->dataPointer = dataInserted;
	newNode->next = NULL;

	// Check whether list is empty or not
	bool valid = isEmpty(*head);

	// Insert at begining
	if( false == position ){
		// List is empty
		if( valid ){
			// Make head as start node and put data in it
			*head = newNode;
		}
		// List not empty
		else if( !valid ){
			newNode->next = *head;
			*head = newNode;
		}
	}
	// Insert at end
	else if( true == position ){
		// List is empty
		if( valid ){
			// Make head as start node and put data in it
			*head = newNode;
		}
		else{
			// Go to last position of list
			ListStructurePointer node;
			for( node=*head; node->next!=NULL; node=node->next );
		
			// Insert item at last position
			node->next = newNode;
		}
	}
	return 0;
}


bool List_::removeItem( ListStructurePointer * head, bool position ){
	
	// Check whether list is empty or not !
	if( isEmpty(*head) ){
		cout<< "Could not delete item it is First item in List" << endl;
		return 1;
	}

	// Find the position of item to be deleted
	else if( !position ){// Delete first item from list
		// Taking temporary node
		ListStructurePointer temp;
		// Put head in temp node
		temp = *head;
		// Make head point to its successive node
		*head = (*head)->next;
		// Delete memory allocated fro data pointed by node
		free(temp->dataPointer);
		// Delete memory allocated for node pointed by temp i.e., start node
		free(temp);
	}

	else if( position ){// Delete last item from list
		// Taking temporary node and previous node
		ListStructurePointer temp = *head, prev = *head;

		// Go to last position
		for( ; temp->next!=NULL; temp=temp->next ){
			// Store node previous to temp in prev i.e., second last node
			prev = temp;
		}

		// Make prev node as last node by making its next as NULL 
		prev->next=NULL;
		// Delete memory allocated fro data pointed by node
		free(temp->dataPointer);
		// Delete memory allocated to last node pointed by temp
		free(temp);
	}
	return 0;
}

void List_:: display( ListStructurePointer *head ){
	if( isEmpty( *head ) ){
		cout<< "No Items to Display" << endl;
		return;
	}

	ListStructurePointer node = *head;
	// Display each element in list
	while( node != NULL ){
		cout<< node->dataPointer << endl ;
		node = node->next;
	}
	cout<< endl;
}


void List_::diplayReverse( ListStructurePointer * head ){

	if( NULL == *head )	return;

	diplayReverse(&(*head)->next);
	printf("%s\n", (*head)->dataPointer);
}


bool List_::deleteList( ListStructurePointer *head ){
	// While there is an item in list delete the last item
	while( !isEmpty(*head) ){
		// Remove utem from last position
		removeItem( head );
	}

	cout<< "List is empty Now" << endl;
	return 0;
}


bool List_::reverse( ListStructurePointer *head ){
	// Check whether list is empty or not
	if( isEmpty(*head) ) return false;

	// Taking local variable
	ListStructurePointer prev = NULL;
	ListStructurePointer current = *head;
	ListStructurePointer next = NULL;

	// push data in stack while NULL is not found
	while( current != NULL ){
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}

	*head = prev;
return true;
}