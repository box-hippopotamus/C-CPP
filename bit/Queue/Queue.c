#include "Queue.h"


//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//����
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

//���루ֻ��β�壩
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

	if (pq->phead == NULL)//û��Ԫ�����⴦��
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

//���ӣ�ֻ��ͷ����
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);

	//��ֻ��һ���ڵ��ʱ��phead��ptail��delָ��ͬһ��ռ䣬free��del��ptail��Ұָ��
	if (pq->phead == NULL)
		pq->ptail = NULL;
	pq->size--;
}

//���ͷ�ڵ�
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

//���β�ڵ�
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//�п�
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

//��ӳ�
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}