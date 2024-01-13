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

//交换
void Swap(int* p1, int* p2);

// 插入排序
void InsertSort(int* a, int n);

// 希尔排序
void ShellSort(int* a, int n);

// 选择排序
void SelectSort(int* a, int n);

// 堆排序
void AdjustDwon(int* a, int n, int root);

void HeapSort(int* a, int n);

// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int begin, int end);

// 快速排序挖坑法
int PartSort2(int* a, int begin, int end);

// 快速排序前后指针法
int PartSort3(int* a, int begin, int end);

void QuickSort(int* a, int begin, int end);

// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end);

// 归并排序递归实现
void _MergeSort(int* a, int begin, int end, int* tmp);
void MergeSort(int* a, int n);

// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);

// 测试排序的性能对比
void TestOP();