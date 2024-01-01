#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLNDataType;

//single list
typedef struct SListNode
{
	SLNDataType val;
	struct SListNode* next;
}SLNode;

//输出链表
void SLTPrint(SLNode* phead);

//创建新节点
SLNode* CreateNode(SLNDataType x);

//尾插
void SLTPushBack(SLNode** pphead, SLNDataType x);

//头插
void SLTPushFront(SLNode** pphead, SLNDataType x);

//尾删
void SLTPopBack(SLNode** pphead);

//头删
void SLTPopFront(SLNode** pphead);

//查找
SLNode* SLTFinde(SLNode* phead, SLNDataType x);

//在pos位置前插入一个节点
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x);

//不使用头指针在pos前插入：
void SLTInsert2(SLNode* pos, SLNDataType x);

//删除pos位置
void SLTErase(SLNode** pphead, SLNode* pos);

//销毁顺序表
void SLTDestroy(SLNode** pphead);
 
//在pos后插入
void SLTInsertAfter(SLNode* pos, SLNDataType x);

//在pos后删除
void SLTErasetAfter(SLNode* pos);

