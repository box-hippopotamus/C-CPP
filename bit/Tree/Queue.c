#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	tmp->next = NULL;
	tmp->data = data;
	

	if (q->phead == NULL)
	{
		q->phead = q->ptail = tmp;
	}
	else
	{
		q->ptail->next = tmp;
		q->ptail = tmp;
	}

	q->size++;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->phead);

	QNode* next = q->phead->next;
	free(q->phead);
	q->phead = next;
	if (q->phead == NULL)
		q->ptail = NULL;
	q->size--;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead);

	return q->phead->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->phead);

	return q->ptail->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);

	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->phead == NULL;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->phead;

	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}