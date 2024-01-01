#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//标识栈顶位置
	int capacity;//当前栈结构总空间大小
}ST;

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
	//当前没有元素，设为-1.保证后续有元素的时候，top对应栈顶元素
	//如果此处设为0，则后续top的对应的就是top后一个元素（也刚好是数据个数）
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
//栈顶插入
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity ? pst->capacity * 2 : 4;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

//栈顶删除
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

//找到栈顶
STDataType STTop(ST* pst)
{
	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);

	//if (pst->top == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	//return pst->top == 0 ? true : false;
	return pst->top == 0;//此处如果为0，返回的就是1，即true，否则返回0，即false
}


/*---------------------------------------以上为栈的实现-------------------------------------*/
typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

	STInit(&obj->pushst); 
	STInit(&obj->popst);//初始化
	return obj;
}

void myQueuePush(MyQueue* obj, int x) 
{
	assert(obj);
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) 
{
	int front = myQueuePeek(obj);//利用peek函数来倒置数据，并取出”栈“顶元素
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) 
{
	if (STEmpty(&obj->popst))//如果出数据的栈为空
	{
		//将数据倒置pop队列
		while (!STEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) 
{
	return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}

void myQueueFree(MyQueue* obj) 
{
	STDestroy(&obj->popst);
	STDestroy(&obj->pushst);

	free(obj);
}

int main()
{


	return 0;
}