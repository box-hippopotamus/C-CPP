#pragma once

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
void QueueInit(Queue* pq);

//����
void QueueDestroy(Queue* pq);

//���루ֻ��β�壩
void QueuePush(Queue* pq, QDataType x);

//���ӣ�ֻ��ͷ����
void QueuePop(Queue* pq);

//���ͷ�ڵ�
QDataType QueueFront(Queue* pq);

//���β�ڵ�
QDataType QueueBack(Queue* pq);

//�п�
bool QueueEmpty(Queue* pq);

//��ӳ�
int QueueSize(Queue* pq);