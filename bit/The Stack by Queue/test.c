#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//��ʶջ��λ��
	int capacity;//��ǰջ�ṹ�ܿռ��С
}ST;

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
	//��ǰû��Ԫ�أ���Ϊ-1.��֤������Ԫ�ص�ʱ��top��Ӧջ��Ԫ��
	//����˴���Ϊ0�������top�Ķ�Ӧ�ľ���top��һ��Ԫ�أ�Ҳ�պ������ݸ�����
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
//ջ������
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity ? pst->capacity * 2 : 4;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

//ջ��ɾ��
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

//�ҵ�ջ��
STDataType STTop(ST* pst)
{
	return pst->a[pst->top - 1];
}

//�п�
bool STEmpty(ST* pst)
{
	assert(pst);

	//if (pst->top == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	//return pst->top == 0 ? true : false;
	return pst->top == 0;//�˴����Ϊ0�����صľ���1����true�����򷵻�0����false
}


/*---------------------------------------����Ϊջ��ʵ��-------------------------------------*/
typedef struct {
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));

	STInit(&obj->pushst); 
	STInit(&obj->popst);//��ʼ��
	return obj;
}

void myQueuePush(MyQueue* obj, int x) 
{
	assert(obj);
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) 
{
	int front = myQueuePeek(obj);//����peek�������������ݣ���ȡ����ջ����Ԫ��
	STPop(&obj->popst);
	return front;
}

int myQueuePeek(MyQueue* obj) 
{
	if (STEmpty(&obj->popst))//��������ݵ�ջΪ��
	{
		//�����ݵ���pop����
		while (!STEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) 
{
	return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}

void myQueueFree(MyQueue* obj) 
{
	STDestroy(&obj->popst);
	STDestroy(&obj->pushst);

	free(obj);
}

int main()
{


	return 0;
}