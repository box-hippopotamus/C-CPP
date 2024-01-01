#include "Queue.h"


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

	if (pq->phead == NULL)//没有元素特殊处理
	{
		pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;	
	}
	pq->ptail = newnode;
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