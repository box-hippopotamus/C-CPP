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

//��ʼ��
ListNode* LTInt();

// �������.
ListNode* ListCreate(LTDataType x);

// ˫����������
void ListDestory(ListNode* pHead);

// ˫�������ӡ
void ListPrint(ListNode* pHead);

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);

// ˫������βɾ
void ListPopBack(ListNode* pHead);

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* pHead);

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);