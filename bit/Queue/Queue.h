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

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestroy(Queue* pq);

//插入（只能尾插）
void QueuePush(Queue* pq, QDataType x);

//出队（只能头出）
void QueuePop(Queue* pq);

//查队头节点
QDataType QueueFront(Queue* pq);

//查队尾节点
QDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);

//求队长
int QueueSize(Queue* pq);