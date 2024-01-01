#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//��ʶջ��λ��
	int capacity;//��ǰջ�ṹ�ܿռ��С
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

//ջ������
void STPush(ST* pst, STDataType x);

//ջ��ɾ��
void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);


