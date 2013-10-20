#include <stdio.h>
#include <stdlib.h>

void test()
{
	int stack2 = 2;
	printf("stack2 = %p\n", &stack2);
}

int main()
{
	int stack1 = 1;
	printf("stack1 = %p\n", &stack1);

	test();

	int * heap1 = malloc(sizeof(int));
	int * heap2 = malloc(sizeof(int));

	printf("heap1 = %p\nheap2 = %p\n", heap1, heap2);

	return 0;
}