#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* a;
    int front;
    int back;
    int k;//最多存k个数据
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));//开k+1个节点
    obj->front = 0;
    obj->back = 0;
    obj->k = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->front == obj->back;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return (obj->back + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if (myCircularQueueIsFull(obj))
        return false;

    obj->a[obj->back] = value;
    obj->back++;

    obj->back %= obj->k + 1;//防止越界
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    obj->front %= obj->k + 1;//防止越界

    return true;
}

//输出队头
int myCircularQueueFront(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[obj->front];
}

//输出队尾
int myCircularQueueRear(MyCircularQueue* obj) 
{
    //return obj->back == 0 ? obj->a[obj->k] : obj->a[obj->back - 1];

    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }

    return obj->a[(obj->back - 1 + obj->k + 1) % (obj->k + 1)];//下式为简化

    //return obj->a[(obj->back + obj->k) % (obj->k + 1)];
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    free(obj->a);
    free(obj);
}