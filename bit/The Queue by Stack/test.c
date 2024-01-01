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

	if (pq->ptail == NULL)//û��Ԫ�����⴦��
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


//-----------------------------------------����Ϊ����ʵ��-------------------------------------------------//

typedef struct
{
	//�˴�q1��q���ǽṹ�壬��������Ҫ&ȡ��ַ
	Queue q1;
	Queue q2;
} MyStack;

//����ջ����ʼ��
MyStack* myStackCreate()
{
	//����ջ
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	//�����������е�ģ��ջ��
	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

//ģ����ջ
void myStackPush(MyStack* obj, int x)
{
	//˭��Ϊ�գ�����˭������
	if (!QueueEmpty(&obj->q1))//->���ȼ��ߣ������ȷ��ʵ�q1����ȡ��ַ
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

//ģ���ջ������ջԪ��
int myStackPop(MyStack* obj)
{
	//˭��Ϊ�գ���˭��ջ
	//����q1Ϊ�գ�q2��Ϊ��
	Queue* emptyq = &obj->q1;
	Queue* nonemptyq = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyq = &obj->q2;
		nonemptyq = &obj->q1;
	}

	//�ǿն���ǰn-1��Ԫ�ص��뵽��һ�����У����µ����һ��Ԫ��"��ջ"
	while (QueueSize(nonemptyq) > 1)
	{
		QueuePush(emptyq, QueueFront(nonemptyq));//�ǿյĶ��в��Һ󣬷��ظ�push��push���ն���
		QueuePop(nonemptyq);//��ǰ�ķǿն��еģ���ͷ����
	}

	int top = QueueFront(nonemptyq);//ȡ��"��ջ"Ԫ�ص�ֵ
	QueuePop(nonemptyq);//"��ջ"Ԫ��
	return top;
}

//ȡջ��Ԫ��
int myStackTop(MyStack* obj)
{
	//˭��Ϊ�գ�����˭ȡ����
	if (!QueueEmpty(&obj->q1))//->���ȼ��ߣ������ȷ��ʵ�q1����ȡ��ַ
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