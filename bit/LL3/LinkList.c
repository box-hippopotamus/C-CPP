
#include "LinkList.h"

//�������
void SLTPrint(LLNode* phead)
{
	//�����ԣ�phead����Ϊ��
	LLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//�����ڵ�
LLNode* CreateNode(LLNDataType x)
{
	//�����ռ䣬����ָ��newnodeά���˽ڵ�
	LLNode* newnode = (LLNode*)malloc(sizeof(LLNode));
	if (newnode == NULL)//ȷ�����ٳɹ�
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->val = x;//��val��ֵΪָ��Ԫ��
	newnode->next = NULL;//���˽ڵ��ָ����NULL
	return newnode;//���˽ڵ��ָ�뷵��
}

//ͷ��
void LLTPushFront(LLNode** pphead, LLNDataType x)
{
	assert(pphead);//ȷ��ָ����Ч��
	LLNode* newnode = CreateNode(x);//���պ��������Ľڵ��ָ��
	newnode->next = *pphead;//�Ƚ�*pphead��ֵ����newnode->next
	*pphead = newnode; 	//�ٽ�newnode�ĵ�ַ����*pphead
}

//β��
void LLTPushBack(LLNode** pphead, LLNDataType x)
{
	assert(pphead);//ȷ��ָ����Ч��

	LLNode* newnode = CreateNode(x);//�����ڵ�
	if (*pphead == NULL)//�˴���Ҫ�ı�phead������Ҫ����pphead
	{
		*pphead = newnode;//�����������޸�phead
	}
	else
	{
		LLNode* tail = *pphead;//������ʱ����
		while (tail->next != NULL)//��β
		{
			tail = tail->next;
		}
		tail->next = newnode;
		//��β�ڵ��nextָ���Աָ���½ڵ㣬�˺��½ڵ�����µ�β�ڵ���
	}
}

//ͷɾ
void LLTPopFront(LLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	LLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

//βɾ
void LLTPopBack(LLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)//����һ���ڵ��nextΪ�գ�˵��������ֻ��һ���ڵ㡣
	{//��������һ��Ԫ�ص����ã������ٵ���һ��Ԫ�غ�Ҫ��phead�ÿ�
		free(*pphead);//freeͷ�ڵ�
		(*pphead) = NULL;	//�ÿ�phead
	}
	else
	{
		LLNode* tail = *pphead;//���ָ��β����ָ��
		LLNode* prev = NULL;//���ָ��β�ڵ�ǰһ���ڵ��ָ��

		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);//free��ԭ��β�ڵ�
		tail = NULL;//����free���ÿյ�ϰ�ߣ�����Ұָ�롣
		prev->next = NULL;  //��ԭ�ȴ�ס�ĵ����ڶ����ڵ��next�ÿ�
	}
}

//����
LLNode* LLTFinde(LLNode* phead, LLNDataType x)
{
	assert(phead);

	LLNode* cur = phead;
	while (cur)//��ѭ�����ڱ�������
	{
		if (cur->val == x)//����������˵���ҵ��ڵ㣬����ָ��
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//��posλ��ǰ����һ���ڵ�
void LLTInsert(LLNode** pphead, LLNode* pos, LLNDataType x)
{//���ڵ��������޷��ҵ���һ��Ԫ�صĵ�ַ������Ҫ�ٴ���һ��ͷָ��
	assert(pphead);
	assert((pos && *pphead) || (!pos && !*pphead));//Ҫô���ǿգ�Ҫô�����ǿ�

	if (*pphead == pos)
	{
		//if������˵��Ϊ������ֱ�ӽ���ͷ��
		LLTPushFront(pphead, x);
	}
	else
	{
		LLNode* prev = *pphead;//�ҵ�Ŀ��λ��ǰһ���ڵ�
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		LLNode* newnode = CreateNode(x);//�˴��ĸ�ֵ˳����ǰ������
		prev->next = newnode;
		newnode->next = pos;
	}
}

//��ʹ��ͷָ����posǰ���룺
void LLTInsert2(LLNode* pos, LLNDataType x)
{
	assert(pos);
	LLTInsertAfter(pos, x);//��pos�����

	pos->next->val = pos->val;//����pos��pos���½��ڵ�����ݣ��൱����posǰ����
	pos->val = x;
}

//��pos�����
void LLTInsertAfter(LLNode* pos, LLNDataType x)
{
	assert(pos);
	LLNode* newnode = CreateNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//��pos��ɾ��
void LLTErasetAfter(LLNode* pos)
{
	assert(pos);
	assert(pos->next);

	LLNode* tmp = pos->next->next;//����tmp�洢pos�����¸��ڵ�
	free(pos->next);//�ͷ�pos�ڵ����һ���ڵ�
	pos->next = tmp;//��pos->nextָ�����¸��ڵ�
}

//ɾ��posλ��
void LLTErase(LLNode** pphead, LLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)//��������ֻ��һ��Ԫ���������ֹ��ָ��
	{
		//ͷɾ
		LLTPopFront(pphead);
	}
	else
	{
		LLNode* prev = *pphead;
		while (prev->next != pos)//������ֿ����۵�һ��Ԫ�أ��˴�prev��Զ�Ҳ���pos����ѭ�������
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//��������
void LLTDestroy(LLNode** pphead)
{
	assert(pphead);
	LLNode* cur = *pphead;

	while (cur)
	{
		LLNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*pphead = NULL;
}