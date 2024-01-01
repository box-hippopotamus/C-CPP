#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

//插入（只能尾插）
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}

	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)//没有元素特殊处理
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

//出队（只能头出）
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);

	//当只有一个节点的时候，phead，ptail与del指向同一块空间，free掉del后，ptail是野指针
	if (pq->phead == NULL)
		pq->ptail = NULL;
	pq->size--;
}

//查队头节点
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

//查队尾节点
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//判空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//求队长
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}


//-----------------------------------------以上为队列实现-------------------------------------------------//

typedef struct
{
	//此处q1与q都是结构体，后续传参要&取地址
	Queue q1;
	Queue q2;
} MyStack;

//创建栈并初始化
MyStack* myStackCreate()
{
	//创建栈
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//创建两个队列到模拟栈中
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

//模拟入栈
void myStackPush(MyStack* obj, int x)
{
	//谁不为空，就向谁插数据
	if (!QueueEmpty(&obj->q1))//->优先级高，所以先访问到q1后再取地址
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

//模拟出栈并返回栈元素
int myStackPop(MyStack* obj)
{
	//谁不为空，用谁出栈
	//假设q1为空，q2不为空
	Queue* emptyq = &obj->q1;
	Queue* nonemptyq = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyq = &obj->q2;
		nonemptyq = &obj->q1;
	}

	//非空队列前n-1个元素导入到另一个队列，留下的最后一个元素"出栈"
	while (QueueSize(nonemptyq) > 1)
	{
		QueuePush(emptyq, QueueFront(nonemptyq));//非空的队列查找后，返回给push，push到空队列
		QueuePop(nonemptyq);//当前的非空队列的，队头出队
	}

	int top = QueueFront(nonemptyq);//取出"出栈"元素的值
	QueuePop(nonemptyq);//"出栈"元素
	return top;
}

//取栈顶元素
int myStackTop(MyStack* obj)
{
	//谁不为空，就向谁取数据
	if (!QueueEmpty(&obj->q1))//->优先级高，所以先访问到q1后再取地址
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/