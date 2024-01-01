#include "SeqList.h"

//初始化顺序表
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//销毁顺序表
void SLDestroy(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

//判断空间是否充足
void SLCheckCapacity(SL* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		SLDataType NewCapacity = psl->capacity == 0 ? 4 : 2 * psl->capacity;

		SLDataType* tmp = (SLDataType*)realloc(psl->a, NewCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		psl->a = tmp;
		psl->capacity = NewCapacity;
	}
}


//头插
void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);

	for (int i = psl->size; i > 0; i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	*psl->a = x;
	psl->size++;
}


//尾插
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

//头删
void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);

	for (int i = 0; i < psl->size - 1; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}

	psl->size--;
}

//尾删
void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
} 

//任意下标位置的插入
void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);//保证数据连续，符合顺序表定义
	SLCheckCapacity(psl);

	for (int i = psl->size; i > pos; i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	psl->a[pos] = x;
	psl->size++;
}

//任意下标位置的删除
void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(psl->size > 0);

	for (int i = pos; i < psl->size - 1; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}

//查找数据，找到返回下标，没找到返回-1
int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return 0;
}


//打印顺序表
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
