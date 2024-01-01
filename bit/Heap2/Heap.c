#include "Heap.h"

// 堆的构建
void HeapCreate(Heap* hp)
{
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void swap(HPDataType* a, int child, int parent)
{
	HPDataType tmp = a[child];
	a[child] = a[parent];
	a[parent] = tmp;
}
//---------------------------------------------------//

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(a, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//向下调整
void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child = child + 1;
		}

		if (a[child] < a[parent])
		{
			swap(a, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(-1);
		}

		hp->a = tmp;
		hp->capacity = newcapacity;
	}

	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	swap(hp->a, 0, hp->size);
	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	if (!HeapEmpty(hp))
	{
		return hp->a[0];
	}
	return -1;
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}