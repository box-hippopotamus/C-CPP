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

//初始化
void HeapInit(HP* php);

//销毁
void HeapDestroy(HP* php);

//-----------------------------------//
// 以下区域传参传入的都是结构体的第一个成员，这样可以让这几个接口同样适用于数组
// 从而达到将一个乱序数组转化为堆的作用
//交换
void Swap(HPDataType* p1, HPDataType* p2);

//向上调整
void AdjustUp(HPDataType* a, int child);

//向下调整
void AdjustDown(HPDataType* a, int size, int parent);

//-----------------------------------//

//插入
void HeapPush(HP* php, HPDataType x);

//删除
void HeapPop(HP* php);

//返回堆顶
HPDataType HeapTop(HP* php);

//求堆的元素个数
size_t HeapSize(HP* php);

//判空
bool HeapEmpty(HP* php);

//--------------------------------------------------------------------------//

