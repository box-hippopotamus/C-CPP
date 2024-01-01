#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LLNDataType;


typedef struct LinkListNode
{
	LLNDataType val;
	struct LinkListNode* next;
}LLNode;//重命名链表的节点为LLNode

//输出链表
void SLTPrint(LLNode* phead);

//创建节点
LLNode* CreateNode(LLNDataType x);

//头插
void LLTPushFront(LLNode** pphead, LLNDataType x);

//尾插
void LLTPushBack(LLNode** pphead, LLNDataType x);

//头删
void LLTPopFront(LLNode** pphead);

//尾删
void LLTPopBack(LLNode** pphead);

//查找
LLNode* LLTFinde(LLNode* phead, LLNDataType x);

//在pos位置前插入一个节点
void LLTInsert(LLNode** pphead, LLNode* pos, LLNDataType x);

//不使用头指针在pos前插入：
void LLTInsert2(LLNode* pos, LLNDataType x);

//在pos后插入
void LLTInsertAfter(LLNode* pos, LLNDataType x);

//在pos后删除
void LLTErasetAfter(LLNode* pos);

//删除pos位置
void LLTErase(LLNode** pphead, LLNode* pos);

//销毁链表
void LLTDestroy(LLNode** pphead);