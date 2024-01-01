#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;
	int capacity;
}SL;


//���˳���ռ��Ƿ����
void SLCheck(SL* psl);

//��ʼ��
void SLInit(SL* psl);

//����
void SLDestroy(SL* psl);

//ͷ��
void SLPushFront(SL* psl, SLDataType x);

//β��
void SLPushBack(SL* psl, SLDataType x);

//ͷɾ
void SLPopFront(SL* psl);

//βɾ
void SLPopBack(SL* psl);

//�±����
void SLInsert(SL* psl, int pos, SLDataType x);

//�±�ɾ��
void SLErase(SL* psl, int pos);

//���˳���
void SLPrint(SL* psl);