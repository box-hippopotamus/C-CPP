#include "stack.h"

int main()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);
	StackPush(&st, 7);
	StackPush(&st, 8);
	StackPush(&st, 9);

	while (!StackEmpty(&st))
	{
		printf("%d - ", StackTop(&st));
		StackPop(&st);
	}

	return 0;
}