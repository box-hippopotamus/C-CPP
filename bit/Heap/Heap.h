#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

typedef int HPDataType;

typedef struct Heap{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//��ʼ��
void HeapInit(HP* php);

//����
void HeapDestroy(HP* php);

//-----------------------------------//
// �������򴫲δ���Ķ��ǽṹ��ĵ�һ����Ա�������������⼸���ӿ�ͬ������������
// �Ӷ��ﵽ��һ����������ת��Ϊ�ѵ�����
//����
void Swap(HPDataType* p1, HPDataType* p2);

//���ϵ���
void AdjustUp(HPDataType* a, int child);

//���µ���
void AdjustDown(HPDataType* a, int size, int parent);

//-----------------------------------//

//����
void HeapPush(HP* php, HPDataType x);

//ɾ��
void HeapPop(HP* php);

//���ضѶ�
HPDataType HeapTop(HP* php);

//��ѵ�Ԫ�ظ���
size_t HeapSize(HP* php);

//�п�
bool HeapEmpty(HP* php);

//--------------------------------------------------------------------------//

