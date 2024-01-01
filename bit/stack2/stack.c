#include "stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity ? ps->capacity * 2 : 4;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("calloc fail");
			return;
		}

		ps->a = tmp;
		ps->capacity = newcapacity;
	}

	ps->a[ps->top] = data;
	ps->top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top);

	ps->top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top);

	return ps->a[ps->top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}