#include "SeqList.h"

//��ʼ��˳���
void SLInit(SL* psl)
{
	assert(psl);
	psl->a = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//����˳���
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

//�жϿռ��Ƿ����
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


//ͷ��
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


//β��
void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);

	psl->a[psl->size] = x;
	psl->size++;
}

//ͷɾ
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

//βɾ
void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
} 

//�����±�λ�õĲ���
void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->size);//��֤��������������˳�����
	SLCheckCapacity(psl);

	for (int i = psl->size; i > pos; i--)
	{
		psl->a[i] = psl->a[i - 1];
	}
	psl->a[pos] = x;
	psl->size++;
}

//�����±�λ�õ�ɾ��
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

//�������ݣ��ҵ������±꣬û�ҵ�����-1
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


//��ӡ˳���
void SLPrint(SL* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}
