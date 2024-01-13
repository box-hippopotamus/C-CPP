#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <memory.h>

#include "stack.h"

//����
void Swap(int* p1, int* p2);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int root);

void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int begin, int end);

// ���������ڿӷ�
int PartSort2(int* a, int begin, int end);

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end);

void QuickSort(int* a, int begin, int end);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int begin, int end);

// �鲢����ݹ�ʵ��
void _MergeSort(int* a, int begin, int end, int* tmp);
void MergeSort(int* a, int n);

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);

// ������������ܶԱ�
void TestOP();