#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
typedef int LTDataType;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//初始化
ListNode* LTInt();

// 创建结点.
ListNode* ListCreate(LTDataType x);

// 双向链表销毁
void ListDestory(ListNode* pHead);

// 双向链表打印
void ListPrint(ListNode* pHead);

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* pHead);

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* pHead);

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);