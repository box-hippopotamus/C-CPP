#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}

// ��β����� 
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

// ��ͷ������ 
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

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->phead);

	return q->phead->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->phead);

	return q->ptail->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);

	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->phead == NULL;
}

// ���ٶ��� 
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