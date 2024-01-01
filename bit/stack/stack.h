#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//标识栈顶位置
	int capacity;//当前栈结构总空间大小
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

//栈顶插入
void STPush(ST* pst, STDataType x);

//栈顶删除
void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);


