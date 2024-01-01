#include "LT.h"

//��ʼ��
ListNode* LTInt()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	pHead->next = pHead;
	pHead->prev = pHead;
	return pHead;
}

// �������.
ListNode* ListCreate(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	ListNode* next = NULL;

	while (cur != pHead)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	pHead->prev = pHead;
	pHead->next = pHead;
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;

	printf("pHead <-> ");
	while(cur != pHead)
	{
		printf("%d <-> ", cur->data);
		cur = cur->next;
	}
	printf("pHead\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	/*ListNode* tail = pHead->prev;
	ListNode* newnode = ListCreate(x);
	
	newnode->next = pHead;
	pHead->prev = newnode;
	tail->next = newnode;
	newnode->prev = tail;*/

	ListInsert(pHead, x);
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* tail = pHead->prev;

	//tail->prev->next = pHead;
	//pHead->prev = tail->prev;
	//free(tail);
	//tail = NULL;
	ListErase(tail);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	//ListNode* newnode = ListCreate(x);

	//pHead->next->prev = newnode;
	//newnode->next = pHead->next;
	//newnode->prev = pHead;
	//pHead->next = newnode;

	ListInsert(pHead->next, x);
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* first = pHead->next;

	/*pHead->next = first->next;
	first->next->prev = pHead;
	free(first);
	first = NULL;*/
	ListErase(first);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* cur = pHead->next;

	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = ListCreate(x);

	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
}
 
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

