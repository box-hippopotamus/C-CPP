#include "stack.h"

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
			return ;
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
	return pst->top == 0;//此处如果为0，返回的就是1，即true，否则返回0，即false
}

