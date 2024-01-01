#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLDataType;//��������޸�˳���ĳ�Ա����

//��̬˳���
 typedef struct SeqList 
{
	SLDataType * a;
	SLDataType size;//��Ч���ݸ���
	SLDataType capacity;//˳���ǰ�ռ��С
}SL;

//typedef struct SeqList SL;//�������˳����ʹ��

 //��˳����ʼ��
 void SLInit(SL* ps); 

//����˳���
 void SLDestroy(SL* ps);

 //ͷ������
 void SLPushFront(SL* ps, SLDataType x);
 //β������
 void SLPushBack(SL* ps, SLDataType x);
 //ͷ��ɾ��
 void SLPopFront(SL* ps);
 //β��ɾ��
 void SLPopBack(SL* ps);

 //���˳���
 void SLPrint(SL* ps); 

 //���˳�����Ϊ��
 bool SLIsEmpty(SL* ps);