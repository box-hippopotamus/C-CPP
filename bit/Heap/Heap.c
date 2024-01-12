#include "Heap.h"

//��ʼ��
void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

//����
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

//����
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])//�����Ϊ��ѣ����˴���[<]��Ϊ����[>]
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

//���µ���
void AdjustDown(HPDataType* a, int size, int parent)//parentΪ���µ����Ŀ�ʼ��
{
	int child = parent * 2 + 1;//��ʱchildΪ����

	while (child < size)
	{
		//����Һ���С�����ӣ�child��Ϊ�Һ���
		//&&��ǰ����������Ǳ�֤�Һ���û��Խ�磬��Ϊ�п���parent���˵����ڶ���
		// ����������ȴû���Һ��ӣ���ʱ�����Һ��Ӿͻ�Խ�磬��&&ǰ��Ĳ�����
		//�ͻ��·��&&�����a[child + 1]�Ͳ������
		if (child + 1 < size && a[child + 1] > a[child])//�����Ϊ��ѣ����˴���[<]��Ϊ����[>]
		{
			child++;
		}

		if (a[child] > a[parent])//�����Ϊ��ѣ����˴���[<]��Ϊ����[>]
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

//����
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

//ɾ��(Ҫ�����ɾ���Ѷ�) ���壺ÿ�ζ���ȡ����Сֵ��С�ѣ�/���ֵ����ѣ�
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;//ɾ��β�ڵ�

	AdjustDown(php->a, php->size, 0);
}

//���ضѶ�
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

//��ѵ�Ԫ�ظ���
size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

//�п�
bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}
