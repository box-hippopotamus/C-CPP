#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LLNDataType;


typedef struct LinkListNode
{
	LLNDataType val;
	struct LinkListNode* next;
}LLNode;//����������Ľڵ�ΪLLNode

//�������
void SLTPrint(LLNode* phead);

//�����ڵ�
LLNode* CreateNode(LLNDataType x);

//ͷ��
void LLTPushFront(LLNode** pphead, LLNDataType x);

//β��
void LLTPushBack(LLNode** pphead, LLNDataType x);

//ͷɾ
void LLTPopFront(LLNode** pphead);

//βɾ
void LLTPopBack(LLNode** pphead);

//����
LLNode* LLTFinde(LLNode* phead, LLNDataType x);

//��posλ��ǰ����һ���ڵ�
void LLTInsert(LLNode** pphead, LLNode* pos, LLNDataType x);

//��ʹ��ͷָ����posǰ���룺
void LLTInsert2(LLNode* pos, LLNDataType x);

//��pos�����
void LLTInsertAfter(LLNode* pos, LLNDataType x);

//��pos��ɾ��
void LLTErasetAfter(LLNode* pos);

//ɾ��posλ��
void LLTErase(LLNode** pphead, LLNode* pos);

//��������
void LLTDestroy(LLNode** pphead);