#include "SeqList.h"

//��ʼ��
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//����
void SLDestroy(SL* psl)
{
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->a = NULL;
		psl->size = 0;
		psl->capacity = 0;
	}
}

//���˳���ռ��Ƿ����
void SLCheck(SL* psl)
{
	if (psl->capacity == psl->size)
	{
		int NewCapacity = psl->capacity == 0 ? 4 : 2 * psl->capacity;

		SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		psl->a = tmp;
		psl->capacity = NewCapacity;
	}
}

//ͷ��
void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheck(psl);

	for (int i = psl->size; i > 0;i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	psl->a[0] = x;
	psl->size++;
}

//β��
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheck(psl);
	psl->a[psl->size] = x;
	psl->size++;
}

//ͷɾ
void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);

	for (int i = 0; i < psl->size; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}

//βɾ
void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}

//�±����
void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);

	for (int i = psl->size; i > pos; i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	psl->a[pos] = x;
	psl->size++;
}

//�±�ɾ��
void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(0 <= pos && pos <= psl->size);


	for (int i = pos; i < psl->size; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}

void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}