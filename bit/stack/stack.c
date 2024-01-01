#include "stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
	//��ǰû��Ԫ�أ���Ϊ-1.��֤������Ԫ�ص�ʱ��top��Ӧջ��Ԫ��
	//����˴���Ϊ0�������top�Ķ�Ӧ�ľ���top��һ��Ԫ�أ�Ҳ�պ������ݸ�����
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}
//ջ������
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

//ջ��ɾ��
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);

	pst->top--;
}

//�ҵ�ջ��
STDataType STTop(ST* pst) 
{
	return pst->a[pst->top - 1];
}

//�п�
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
	return pst->top == 0;//�˴����Ϊ0�����صľ���1����true�����򷵻�0����false
}

