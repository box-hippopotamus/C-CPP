#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;

//����ڵ�
LTNode* CreateNode(LTDataType x);

//��ʼ��
LTNode* LTInit();

//�������
void LTPrint(LTNode* phead);

//β��
void LTPushBack(LTNode* phead, LTDataType x);

//βɾ
void LTPopBack(LTNode* phead);

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

// ͷɾ
void LTPopFront(LTNode* phead);

//���ҽڵ�
LTNode* LTFind(LTNode* phead, LTDataType x);

//��posǰ����
void LTInsert(LTNode* pos, LTDataType x);

//ɾ��posλ��
void LTErase(LTNode* pos);

//��������
void LTErase(LTNode* phead);
