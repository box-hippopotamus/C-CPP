#include "SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);
	SListNode* cur = plist;

	while (cur)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tali = *pplist;
		while (tali->next)
		{
			tali = tali->next;
		}
		tali->next = newnode;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* tail = *pplist;
		SListNode* prev = NULL;

		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);

	SListNode* tmp = (*pplist)->next;
	free(*pplist);
	*pplist = tmp;
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode** pplist,SListNode* pos, SLTDateType x)
{
	assert(pplist);
	if (pos == NULL)
	{
		SListPushFront(pplist, x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		pos->next = newnode;
		newnode->next = pos->next;
	}
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	assert(pos->next);

	SListNode* tmp = pos->next->next;
	free(pos->next);
	pos->next = tmp;
}


// 在pos的前面插入
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x)
{
	assert(pphead);
	assert((pos && *pphead) || (!pos && !*pphead));
	if (pos == NULL)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SListNode* cur = *pphead;

		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SListNode* newnode = BuySListNode(x);
		newnode->next = pos;
		cur->next = newnode;
	}
}

// 删除pos位置
void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pos);
	assert(pphead);
	assert(*pphead);

	SListNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}

void SLTDestroy(SListNode** pphead)
{
	assert(pphead);

	SListNode* cur = *pphead;
	SListNode* tmp = NULL;

	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*pphead = NULL;
}