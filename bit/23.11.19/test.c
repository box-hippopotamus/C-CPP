#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;//标识栈顶位置
	int capacity;//当前栈结构总空间大小
}ST;

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
	//当前没有元素，设为-1.保证后续有元素的时候，top对应栈顶元素
	//如果此处设为0，则后续top的对应的就是top后一个元素（也刚好是数据个数）
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
//栈顶插入
void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity ? pst->capacity * 2 : 4;
		STDataType* tmp = (STDataType*)realloc(pst->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

//栈顶删除
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

//找到栈顶
STDataType STTop(ST* pst)
{
	return pst->a[pst->top - 1];
}

//判空
bool STEmpty(ST* pst)
{
	assert(pst);

	//if (pst->top == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	//return pst->top == 0 ? true : false;
	return (pst->top == 0);//此处如果为0，返回的就是1，即true，否则返回0，即false
}

bool isValid(char* s)
{
	ST st;
	STInit(&st);

	while (*s)
	{
		if (*s == '[' || *s == '(' || *s == '{')
		{
			STPush(&st, *s);
		}
		else
		{
			if (STEmpty(&st))
			{
				STDestroy(&st);//防止从这里出的时候没有销毁，导致内存泄漏
				return false;
			}
			//如果右括号数量大于左括号，此处会访问空栈，导致报错
			char top = STTop(&st);
			STPop(&st);
			//控制顺序不匹配
			if ((top == '[' && *s != ']')
				|| (top == '(' && *s != ')')
				|| (top == '{' && *s != '}'))
			{
				STDestroy(&st);//防止从这里出的时候没有销毁，导致内存泄漏
				return false;
			}
		}
		++s;
	}
	//控制数量不匹配,左括号多于右括号的情况
	bool ret = STEmpty(&st);
	STDestroy(&st);

	return ret;
}

int main()
{
	char* s = "()[]{}";
	isValid(s);

	return 0;
}