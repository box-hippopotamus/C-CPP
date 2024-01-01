#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLNDataType;

//single list
typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

//�������
void SLTPrint(SLNode* phead);

//�����½ڵ�
SLNode* CreateNode(SLNDataType x);

//β��
void SLTPushBack(SLNode** pphead, SLNDataType x);

//ͷ��
void SLTPushFront(SLNode** pphead, SLNDataType x);

//βɾ
void SLTPopBack(SLNode** pphead);

//ͷɾ
void SLTPopFront(SLNode** pphead);

//����
SLNode* SLTFinde(SLNode* phead, SLNDataType x);

//��posλ��ǰ����һ���ڵ�
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);

//��ʹ��ͷָ����posǰ���룺
void SLTInsert2(SLNode* pos, SLNDataType x);

//ɾ��posλ��
void SLTErase(SLNode** pphead, SLNode* pos);

//����˳���
void SLTDestroy(SLNode** pphead);
 
//��pos�����
void SLTInsertAfter(SLNode* pos, SLNDataType x);

//��pos��ɾ��
void SLTErasetAfter(SLNode* pos);

