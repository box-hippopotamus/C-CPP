#include "List.h"

//����ڵ�
LTNode* CreateLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->val = x;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}


//��ʼ��
LTNode* LTInit()
{
	LTNode* phead = CreateLTNode(-5);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//�������
void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("�ڱ� <-> ");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d <-> ", cur->val);
		cur = cur->next;
	}
	printf("�ڱ�\n");
}

//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//���ڱ�λ��ͷ�ڵ㲻����Ϊ��  

	//LTNode* tail = phead->prev;
	//LTNode* newnode = CreateLTNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	LTInsert(phead, x);
}

//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;

	//free(tail);
	//tailprev->next = phead;
	//phead->prev = tailprev;
	LTErase(phead->prev);
}

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = CreateLTNode(x);

	//newnode->next = phead->next;
	//phead->next->prev = newnode;

	//phead->next = newnode;
	//newnode->prev = phead;

	LTInsert(phead->next, x);
}

// ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//LTNode* first = phead->next;
	//LTNode* second = first->next;

	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	LTErase(phead->next);
}

//���ҽڵ�
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//��posǰ����
void LTInsert(LTNode* pos, LTDataType x)
{
	//pos=phead����β��
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = CreateLTNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ��
void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* posNext = pos->next;
	LTNode* posPrev = pos->prev;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
	//û������,��Ҫʹ���������ÿգ��˴��޷����ⲿ��pos�޸�
	//��ʱ�ⲿ��posΪҰָ��
}


//��������
void LTErase(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
	//û������,��Ҫʹ���������ÿ�phead���˴��޷����ⲿ�޸�
    //��ʱ�ⲿ��pheadΪҰָ��
}