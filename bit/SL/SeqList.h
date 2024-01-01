#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLDataType;//方便后续修改顺序表的成员类型

//动态顺序表
 typedef struct SeqList 
{
	SLDataType * a;
	SLDataType size;//有效数据个数
	SLDataType capacity;//顺序表当前空间大小
}SL;

//typedef struct SeqList SL;//方便后续顺序表的使用

 //对顺序表初始化
 void SLInit(SL* ps); 

//销毁顺序表
 void SLDestroy(SL* ps);

 //头部插入
 void SLPushFront(SL* ps, SLDataType x);
 //尾部插入
 void SLPushBack(SL* ps, SLDataType x);
 //头部删除
 void SLPopFront(SL* ps);
 //尾部删除
 void SLPopBack(SL* ps);

 //输出顺序表
 void SLPrint(SL* ps); 

 //检测顺序表是为空
 bool SLIsEmpty(SL* ps);