#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

//顺序表
typedef struct SeqList
{
	SLDataType* a;
	SLDataType size;
	SLDataType capacity;//此处选用二倍扩容是应为cpp中也是使用2倍或1.5倍
}SL;



//初始化顺序表
void SLInit(SL* psl);//使用传址调用

//销毁顺序表
void SLInit(SL* psl);

//判断空间是否充足


//检查顺序表是否为空


//头插
void SLPushFront(SL* psl, SLDataType x);

//尾插
void SLPushBack(SL* psl, SLDataType x);

//头删
void SLPopFront(SL* psl);

//尾删
void SLPopBack(SL* psl);

//输出顺序表
void SLPrint(SL* psl);

//任意下标位置的插入
void SLInsert(SL*psl,int pos,SLDataType x);

//任意下标位置的删除
void SLErase(SL* psl, int pos);

//查找数据，找到返回下标，没找到返回-1
int SLFind(SL* psl, SLDataType x);