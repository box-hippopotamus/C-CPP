#include "Heap.h"

//初始化
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

//销毁
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

//交换
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])//若想改为大堆，将此处的[<]改为大于[>]
		{
			Swap(&a[child], &a[parent]);
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
void AdjustDown(HPDataType* a, int size, int parent)//parent为向下调整的开始点
{
	int child = parent * 2 + 1;//此时child为左孩子

	while (child < size)
	{
		//如果右孩子小于左孩子，child改为右孩子
		//&&的前面的条件，是保证右孩子没有越界，因为有可能parent到了倒数第二层
		// 但是有左孩子却没有右孩子，此时访问右孩子就会越界，若&&前面的不成立
		//就会短路，&&后面的a[child + 1]就不会访问
		if (child + 1 < size && a[child + 1] > a[child])//若想改为大堆，将此处的[<]改为大于[>]
		{
			child++;
		}

		if (a[child] > a[parent])//若想改为大堆，将此处的[<]改为大于[>]
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//插入
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

//删除(要求必须删除堆顶) 意义：每次都能取出最小值（小堆）/最大值（大堆）
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;//删除尾节点

	AdjustDown(php->a, php->size, 0);
}

//返回堆顶
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

//求堆的元素个数
size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

//判空
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
