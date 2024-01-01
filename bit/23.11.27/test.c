#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



typedef struct {
	int* a;
	int head;
	int tail;
	int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) 
{
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}

	int* tmp = (int*)malloc(sizeof(int) * (k + 1));
	if (tmp == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}

	obj->a = tmp;
	obj->head = 0;
	obj->tail = 0;
	obj->k = k;
	return obj;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	assert(obj);
	return obj->tail  == obj->head;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	assert(obj);
	return (obj->tail + 1) % (obj->k + 1) == obj->head;
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
	assert(obj);
	assert(obj->a);
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	else
	{
		obj->a[obj->tail] = value;
		obj->tail = (obj->tail + 1) % (obj->k + 1);
		return true;
	}

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
	assert(obj);
	assert(obj->a);
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	else
	{
		obj->head = ((obj->head + 1) + (obj->k + 1)) % (obj->k + 1);
		return true;
	}
}

int myCircularQueueFront(MyCircularQueue* obj) 
{
	assert(obj);
	assert(obj->a);
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->a[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) 
{
	assert(obj);
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->a[((obj->tail - 1) + (obj->k + 1)) % (obj->k + 1)];
}


void myCircularQueueFree(MyCircularQueue* obj) 
{
	assert(obj);
	assert(obj->a);
	free(obj->a);
	free(obj);
	obj = NULL;
}


int main()
{

	MyCircularQueue*  obj = myCircularQueueCreate(3);
	myCircularQueueEnQueue(obj, 1);
	myCircularQueueEnQueue(obj, 2);
	myCircularQueueEnQueue(obj, 3);
	myCircularQueueEnQueue(obj, 4);

	myCircularQueueRear(obj);

	myCircularQueueIsFull(obj);

	myCircularQueueDeQueue(obj);

	myCircularQueueEnQueue(obj, 4);

	myCircularQueueRear(obj);

	myCircularQueueFree(obj);
	return 0;
}