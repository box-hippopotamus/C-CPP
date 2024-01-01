#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <string.h>

//typedef char STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;//标识栈顶位置
//	int capacity;//当前栈结构总空间大小
//}ST;
//
//void STInit(ST* pst)
//{
//	assert(pst);
//	pst->a = NULL;
//	pst->capacity = 0;
//	pst->top = 0;
//	//当前没有元素，设为-1.保证后续有元素的时候，top对应栈顶元素
//	//如果此处设为0，则后续top的对应的就是top后一个元素（也刚好是数据个数）
//}
//
//void STDestroy(ST* pst)
//{
//	assert(pst);
//
//	free(pst->a);
//	pst->a = NULL;
//	pst->top = pst->capacity = 0;
//}
////栈顶插入
//void STPush(ST* pst, STDataType x)
//{
//	assert(pst);
//
//	if (pst->top == pst->capacity)
//	{
//		int newcapacity = pst->capacity ? pst->capacity * 2 : 4;
//		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		pst->a = tmp;
//		pst->capacity = newcapacity;
//	}
//
//	pst->a[pst->top] = x;
//	pst->top++;
//}
//
////栈顶删除
//void STPop(ST* pst)
//{
//	assert(pst);
//	assert(pst->top > 0);
//
//	pst->top--;
//}
//
////找到栈顶
//STDataType STTop(ST* pst)
//{
//	return pst->a[pst->top - 1];
//}
//
////判空
//bool STEmpty(ST* pst)
//{
//	assert(pst);
//
//	//if (pst->top == 0)
//	//{
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//	//return pst->top == 0 ? true : false;
//	return (pst->top == 0);//此处如果为0，返回的就是1，即true，否则返回0，即false
//}
//
//bool isValid(char* s) 
//{
//	int i = 0;
//
//	ST pst;
//	STInit(&pst);
//
//	for (i = 0; i < strlen(s); i++)
//	{
//		if (s[i] == '[' || s[i] == '(' || s[i] == '{')
//		{
//			STPush(&pst, s[i]);
//		}
//		else
//		{
//			if (STEmpty(&pst))
//			{
//				return false;
//			}
//
//			char right = STTop(&pst);
//			STPop(&pst);
//			if ((s[i] == ']' && right != '[')
//				|| (s[i] == '}' && right != '{')
//				|| (s[i] == ')' && right != '('))
//			{
//				return false;
//			}
//		}
//	}
//
//	if (!STEmpty(&pst))
//	{
//		return false;
//	}
//	return true;
//}
//
//int main()
//{
//	char* s = "()";
//	isValid(s);
//
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	QDataType val;
//	struct QueueNode* next;
//}QNode;
//
//typedef struct Queue
//{
//	QNode* phead;
//	QNode* ptail;
//	int size;
//}Queue;
//
//
////初始化
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->phead = pq->ptail = NULL;
//	pq->size = 0;
//}
//
////销毁
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//
//	QNode* cur = pq->phead;
//	while (cur)
//	{
//		QNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//
//	pq->phead = NULL;
//	pq->ptail = NULL;
//	pq->size = 0;
//}
//
////插入（只能尾插）
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//
//	newnode->val = x;
//	newnode->next = NULL;
//
//	if (pq->ptail == NULL)//没有元素特殊处理
//	{
//		pq->ptail = pq->phead = newnode;
//	}
//	else
//	{
//		pq->ptail->next = newnode;
//		pq->ptail = newnode;
//	}
//	pq->size++;
//}
//
////出队（只能头出）
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->phead);
//
//	QNode* del = pq->phead;
//	pq->phead = pq->phead->next;
//	free(del);
//
//	//当只有一个节点的时候，phead，ptail与del指向同一块空间，free掉del后，ptail是野指针
//	if (pq->phead == NULL)
//		pq->ptail = NULL;
//	pq->size--;
//}
//
////查队头节点
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->phead);
//	return pq->phead->val;
//}
//
////查队尾节点
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->ptail);
//	return pq->ptail->val;
//}
//
////判空
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->phead == NULL;
//}
//
////求队长
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	return pq->size;
//}
//
//
//
////-----------------------------------------以上为队列实现-------------------------------------------------//
//
//
//typedef struct {
//	Queue q1;
//	Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate()
//{
//	//MyStack obj;
//	//QueueInit(&obj.q1);
//	//QueueInit(&obj.q2);
//
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&obj->q1);
//	QueueInit(&obj->q2);
//
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		QueuePush(&obj->q1, x);
//	}
//	else
//	{
//		QueuePush(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		while (obj->q1.size > 1)
//		{
//			QueuePush(&obj->q2, QueueFront(&obj->q1));
//			QueuePop(&obj->q1);
//		}
//		int num = QueueFront(&obj->q1);
//		QueuePop(&obj->q1);
//		return num;
//	}
//	else
//	{
//		while (obj->q2.size > 1)
//		{
//			QueuePush(&obj->q1, QueueFront(&obj->q2));
//			QueuePop(&obj->q2);
//		}
//		int num = QueueFront(&obj->q2);
//		QueuePop(&obj->q2);
//		return num;
//	}
//}
//
//int myStackTop(MyStack* obj)
//{
//	if (!QueueEmpty(&obj->q1))
//	{
//		return QueueBack(&obj->q1);
//	}
//	else
//	{
//		return QueueBack(&obj->q2);
//	}
//}
//
//bool myStackEmpty(MyStack* obj)
//{
//	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//	QueueDestroy(&obj->q1);
//	QueueDestroy(&obj->q2);
//
//	free(obj);
//}
//


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


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

bool myQueueEmpty(MyQueue* obj) 
{
	return STEmpty(&obj->pushst) && STEmpty(&obj->popst);
}

void myQueuePush(MyQueue* obj, int x) 
{
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) 
{
	if (myQueueEmpty(obj))
	{
		return -1;
	}
	else
	{
		if (STEmpty(&obj->popst))
		{
			while (!STEmpty(&obj->pushst))
			{
				STPush(&obj->popst, STTop(&obj->pushst));
				STPop(&obj->pushst);
			}
		}

		int num = STTop(&obj->popst);
		STPop(&obj->popst);
		return num;
	}
}

int myQueuePeek(MyQueue* obj) 
{
	if (myQueueEmpty(obj))
	{
		return -1;
	}
	else
	{
		if (STEmpty(&obj->popst))
		{
			while (!STEmpty(&obj->pushst))
			{
				STPush(&obj->popst, STTop(&obj->pushst));
				STPop(&obj->pushst);
			}
		}
		return STTop(&obj->popst);
	}
}

void myQueueFree(MyQueue* obj) 
{
	free(obj);
}

int main()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePeek(obj);
	myQueuePop(obj);
	myQueueEmpty(obj);
	return 0;
}