#include "List.h"

//申请节点
LTNode* CreateLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}


//初始化
LTNode* LTInit()
{
	LTNode* phead = CreateLTNode(-5);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//输出链表
void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("哨兵 <-> ");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d <-> ", cur->val);
		cur = cur->next;
	}
	printf("哨兵\n");
}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//带哨兵位的头节点不可能为空  

	//LTNode* tail = phead->prev;
	//LTNode* newnode = CreateLTNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	LTInsert(phead, x);
}

//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;

	//free(tail);
	//tailprev->next = phead;
	//phead->prev = tailprev;
	LTErase(phead->prev);
}

//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = CreateLTNode(x);

	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;

	LTInsert(phead->next, x);
}

// 头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	LTErase(phead->next);
}

//查找节点
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//在pos前插入
void LTInsert(LTNode* pos, LTDataType x)
{
	//pos=phead就是尾插
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = CreateLTNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos位置
void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* posNext = pos->next;
	LTNode* posPrev = pos->prev;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
	//没有意义,需要使用者自行置空，此处无法对外部的pos修改
	//此时外部的pos为野指针
}


//销毁链表
void LTErase(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
	//没有意义,需要使用者自行置空phead，此处无法对外部修改
    //此时外部的phead为野指针
}