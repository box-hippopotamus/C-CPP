#include "stack.h"

int main()
{
	ST s;
	STInit(&s);

	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);

	//由于栈的性质，每次只能访问栈顶的元素，想要访问其它元素，必须出栈
	//如果入栈顺序固定，出栈顺序其实不固定，可以在某个值入栈的同时出栈，即还没有完全入栈就出栈了部分数据
	while (!STEmpty(&s))
	{
		printf("%d ", STTop(&s));
		STPop(&s);
	}
	printf("\n");
	return 0;
}