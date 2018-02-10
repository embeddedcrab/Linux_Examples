
/* Include standard headers */
#include "Headers.h"


int main( void ){

	// Declare variable for list header
	ListStructurePointer head = NULL;
	// Create an object for _LIST
	List_ * list = new List_;

	// Add items
	list->addItem( &head, "HEMANT", sizeof("HEMANT"), true );
	list->addItem( &head, "SHARMA", sizeof("SHARMA"), true );
	list->addItem( &head, "HELLO", sizeof( "HELLO"), true );
	list->addItem( &head, "WORLD", sizeof("WORLD"), true );
	// Display list
	list->display( &head );

	
	list->diplayReverse(&head);

	printf("Length of List is %u\n", list->length(&head));

	list->reverse(&head);
	list->display(&head);

	list->deleteList( &head );
	// Display list
	list->display( &head );
	

	getchar();

return 0;
}