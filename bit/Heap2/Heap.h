#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);