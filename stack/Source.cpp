/* Include Headers */
#include "Headers.h"


int main( void ){
	stackStructPointer head = NULL;
	void *data;

	/* Create object for Stack class */
	Stack_ *stack = new Stack_;

	/* Push data onto stack */
	stack->push( &head, "HEMANT", sizeof("HEMANT") );
	printf("%s%s\n", "Data inserted onto stack is : ", "HEMANT");

	/* print TOP of stack */
	printf("Data in Stack is %s\n\n", stack->peek( &head ));

	/* Push data onto stack */
	stack->push( &head, "SHARMA", sizeof("SHARMA") );
	printf("%s %s\n", "Data inserted onto stack is : ", "SHARMA");

	/* POP TOP of stack using a pointer */
	data = (char *)stack->pop(&head);
	printf("Data popped from stack is %s\n", data);
	/* Free memory for data stored in memory which was allocated in pop function to store data from data pointer */
	free(data);

	/* print TOP of stack */
	printf("Data in Stack is %s\n\n", (char *)stack->peek( &head ));

	/* Get TOP in variable */
	data = (char *)stack->pop(&head);
	printf("Data popped from stack is %s\n", data);
	/* Free memory for data stored in memory which was allocated in pop function to store data from data pointer */
	free(data);

	printf("Data in Stack is %s\n", (char *)stack->peek( &head ));

	getchar();

return 0;
}
