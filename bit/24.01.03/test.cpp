#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

////---------------------------------------
//
//typedef struct ListNode* STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST* pst)
//{
//	pst->a = NULL;
//	pst->capacity = 0;
//	pst->top = 0;
//}
//
//void STDestroy(ST* pst)
//{
//	free(pst->a);
//	pst->a = NULL;
//	pst->top = pst->capacity = 0;
//}
//
//void STPush(ST* pst, STDataType x)
//{
//	if (pst->top == pst->capacity)
//	{
//		int newcapacity = pst->capacity ? pst->capacity * 2 : 4;
//		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		pst->a = tmp;
//		pst->capacity = newcapacity;
//	}
//
//	pst->a[pst->top] = x;
//	pst->top++;
//}
//
//void STPop(ST* pst)
//{
//	pst->top--;
//}
//
//STDataType STTop(ST* pst)
//{
//	return pst->a[pst->top - 1];
//}
//
//bool STEmpty(ST* pst)
//{
//	return pst->top == 0;
//}
//
////---------------------------------------
//void SLTPopFront(struct ListNode** pphead)
//{
//	struct ListNode* tmp = (*pphead)->next;
//	free(*pphead);
//	*pphead = tmp;
//}
//
//void SLTErase(struct ListNode** pphead, struct ListNode* pos)
//{
//
//	if (*pphead == pos)
//	{
//		SLTPopFront(pphead);
//	}
//	else
//	{
//		struct ListNode* prev = *pphead;
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//
//		prev->next = pos->next;
//		free(pos);
//		pos = NULL;
//	}
//}
// 
//struct ListNode* removeNodes(struct ListNode* head) 
//{
//    struct ListNode* cur = head;
//
//	ST stack;
//	ST* pst = &stack;
//
//	STInit(pst);
//
//    //struct ListNode* newpHead = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//	//newpHead->next = NULL;
//
//    while (cur != NULL)
//    {
//		if (STEmpty(pst) || STTop(pst)->val >= cur->val )
//		{
//			STPush(pst, cur);
//		}
//		else
//		{
//			while (!STEmpty(pst) && STTop(pst)->val < cur->val)
//			{
//				struct ListNode* top = STTop(pst);
//				STPop(pst);
//				SLTErase(&head, top);
//			}
//			STPush(pst, cur);
//		}
//    }
//
//	return head;
//}

int len(struct ListNode* head)
{
	int n = 0;
	while (head != NULL)
	{
		n++;
		head = head->next;
	}
	return n;
}

struct ListNode* removeNodes(struct ListNode* head)
{
	struct ListNode** st = (struct ListNode**)malloc(sizeof(struct ListNode*) * len(head));
	int top = -1;

	while(head != NULL)
	{
		top++;
		st[top] = head;
		head = head->next;
	}

	while(top >= 0) 
	{
		if (head == NULL || st[top]->val >= head->val)
		{
			st[top]->next = head;
			head = st[top];
		}
		top--;
	}
	return head;
}

int main()
{

	return 0;
}