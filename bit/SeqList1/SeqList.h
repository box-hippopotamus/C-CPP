#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

//˳���
typedef struct SeqList
{
	SLDataType* a;
	SLDataType size;
	SLDataType capacity;//�˴�ѡ�ö���������ӦΪcpp��Ҳ��ʹ��2����1.5��
}SL;



//��ʼ��˳���
void SLInit(SL* psl);//ʹ�ô�ַ����

//����˳���
void SLInit(SL* psl);

//�жϿռ��Ƿ����


//���˳����Ƿ�Ϊ��


//ͷ��
void SLPushFront(SL* psl, SLDataType x);

//β��
void SLPushBack(SL* psl, SLDataType x);

//ͷɾ
void SLPopFront(SL* psl);

//βɾ
void SLPopBack(SL* psl);

//���˳���
void SLPrint(SL* psl);

//�����±�λ�õĲ���
void SLInsert(SL*psl,int pos,SLDataType x);

//�����±�λ�õ�ɾ��
void SLErase(SL* psl, int pos);

//�������ݣ��ҵ������±꣬û�ҵ�����-1
int SLFind(SL* psl, SLDataType x);