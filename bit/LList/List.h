#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define _CRT_SECURE_NO_WARNINGS 1

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;

//申请节点
LTNode* CreateNode(LTDataType x);

//初始化
LTNode* LTInit();

//输出链表
void LTPrint(LTNode* phead);

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

// 头删
void LTPopFront(LTNode* phead);

//查找节点
LTNode* LTFind(LTNode* phead, LTDataType x);

//在pos前插入
void LTInsert(LTNode* pos, LTDataType x);

//删除pos位置
void LTErase(LTNode* pos);

//销毁链表
void LTErase(LTNode* phead);
