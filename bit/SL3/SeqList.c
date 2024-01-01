#include "SeqList.h"

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//增加空间
void SeqListCheck(SeqList* ps)
{
	if (ps->capacity == ps->size)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;

		SeqList* tmp = (SeqList*)realloc(ps->a, sizeof(SeqList) * NewCapacity);
		if (tmp == NULL)
		{
			perror("calloc fail!");
			exit(1);
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}

//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheck(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头插
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheck(ps);

	for (int i = ps->size; i > 0;i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}//头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}

	ps->size--;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}


// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return &(ps->a[i]);
		}
	}
	return NULL;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}