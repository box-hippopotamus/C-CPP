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


//检查顺序表空间是否充足
void SLCheck(SL* psl);

//初始化
void SLInit(SL* psl);

//销毁
void SLDestroy(SL* psl);

//头插
void SLPushFront(SL* psl, SLDataType x);

//尾插
void SLPushBack(SL* psl, SLDataType x);

//头删
void SLPopFront(SL* psl);

//尾删
void SLPopBack(SL* psl);

//下标插入
void SLInsert(SL* psl, int pos, SLDataType x);

//下标删除
void SLErase(SL* psl, int pos);

//输出顺序表
void SLPrint(SL* psl);