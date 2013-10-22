#include <stdio.h>
#include <stdlib.h>

void testStack()
{
	int stack2 = 2;
	printf("stack2 = %p\n", &stack2);
}

void testHeap()
{
	int * heap2 = malloc(sizeof(int));
	printf("heap2 = %p\n", heap2);
}

int main()
{
	int stack1 = 1;
	printf("stack1 = %p\n", &stack1);

	testStack();

	int * heap1 = malloc(sizeof(int));
	printf("heap1 = %p\n", heap1);

	testHeap();

	return 0;
}