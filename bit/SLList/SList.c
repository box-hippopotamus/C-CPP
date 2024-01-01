#include "SList.h"

//�������
void SLTPrint(SLNode* phead)
{
	//�����ԣ�phead����Ϊ��
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->",cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//�����½ڵ� 
SLNode* CreateNode(SLNDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}  


//β��
void SLTPushBack(SLNode** pphead, SLNDataType x)
 {
	assert(pphead);
	//ע��˴�������newnode��tail��pphead������ʱ��������������ʱ��������
	//����malloc���ٵĿռ�����洢�����ݱ����������ô�ַ���ã�����һ�ڵ��ֵҲ�ı�
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)//�˴���Ҫ�ı�phead������Ҫ����pphead
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)//��β
		{
			tail = tail->next;
		}
		tail->next = newnode;//�˴�Ҫ�ı�һ���ṹ���е�next��Ա������tail�Ѿ��ǽṹ��ĵ�ַ�����ʺ�Ϳ���ֱ���޸�next��ֵ
	}
}

//ͷ��
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode; 	
}

//βɾ
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{//��������һ��Ԫ�ص����ã������ٵ���һ��Ԫ�غ�Ҫ��phead�ÿ�
		free(*pphead);
		(*pphead) = NULL;	
	}
	else
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		//��������
		//ע�⣺�˴�prev���ܳ�ʼ��Ϊ*pphead������������ֻ��һ��Ԫ�أ����߶���pphead��free��tailָ���Ԫ�غ�,prevָ��ľ���Ұָ��
		//��������
		while (tail->next != NULL) 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);//�˴������ÿ�tail����Ϊ���˺���tail�Զ�������
		tail = NULL;
		prev->next = NULL;  
	}
}

////βɾ2
//void SLTPopBack(SLNode** pphead)
//{
//	assert(*pphead);
//
//	SLNode* tail = *pphead;
//	SLNode* prev = NULL;
//	//��������
//	//ע�⣺�˴�prev���ܳ�ʼ��Ϊ*pphead������������ֻ��һ��Ԫ�أ����߶���pphead��free��tailָ���Ԫ�غ�,prevָ��ľ���Ұָ��
//	//��������
//	while (tail->next != NULL)
//	{
//		prev = tail;
//		tail = tail->next;
//	}
//	free(tail);//�˴������ÿ�tail����Ϊ���˺���tail�Զ�������
//	tail = NULL;
//
//	if (prev == NULL)
//	{
//		*pphead = NULL;
//	}
//	else
//	{
//		prev->next = NULL;
//	}
//}

////βɾ3
//void SLTPopBack(SLNode** pphead)
//{
//	assert(*pphead);
//	if ((*pphead)->next == NULL)
//	{//��������һ��Ԫ�ص����ã������ٵ���һ��Ԫ�غ�Ҫ��phead�ÿ�
//		free(*pphead);
//		(*pphead) = NULL;
//	}
//	else
//	{
//		SLNode* tail = *pphead;
//		while (tail->next->next != NULL)
//		{
//			tail = tail->next;
//		}
//		free(tail->next);//free������nextָ�����һ���ڵ�
//		tail->next = NULL;//�ÿյ��ǵ�ǰ�ڵ��next
//	}
//}

//ͷɾ
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	 
	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
	//�˴������������ֻ��һ��Ԫ���������ֻ��һ��Ԫ�أ�tmp�ᱻ��ֵΪNULL
	//Ȼ��*ppheadҲ������tmp����ֵΪNULL
}

//����
SLNode* SLTFinde(SLNode* phead, SLNDataType x)
{
	assert(phead);

	SLNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//��posλ��ǰ����һ���ڵ�
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{//���ڵ��������޷��ҵ���һ��Ԫ�صĵ�ַ������Ҫ�ٴ���һ��ͷָ��
	assert(pphead);
	//assert(*pphead);//������ԣ��˴�Ϊ��˵������û��Ԫ�أ��Ǿ���ͷ��
	//assert(pos);//������ԣ���*pphead����pheadΪ�գ�û��Ԫ�ص�����£���posǰ����ڵ��൱����NULLǰ����
	assert( (pos && *pphead) || (!pos && !*pphead));//Ҫô���ǿգ�Ҫô�����ǿ�

	if (*pphead == pos)
	{
		//ͷ��
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;//�ҵ�Ŀ��λ��ǰһ���ڵ�
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLNode* newnode = CreateNode(x);
		prev->next = newnode;
		newnode->next = pos; 
	}
}

//��ʹ��ͷָ����posǰ���룺
void SLTInsert2(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLTInsertAfter(pos, x);//��pos�����

	pos->next->val = pos->val;//����pos��pos���½��ڵ�����ݣ��൱����posǰ����
	pos->val = x;
}



//ɾ��posλ��
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)//��������ֻ��һ��Ԫ�أ���ֹ��ָ��
	{
		//ͷɾ
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)//������ֿ����۵�һ��Ԫ�أ��˴�prev��Զ�Ҳ���pos����ѭ�������
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//����˳���
void SLTDestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;

	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;   
}


//��pos�����
void SLTInsertAfter(SLNode* pos, SLNDataType x) 
{
	assert(pos);
	SLNode* newnode = CreateNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//��pos��ɾ��
void SLTErasetAfter(SLNode* pos)
{
	assert(pos);

	SLNode* tmp = pos->next->next;
	free(pos->next);//���pos��β���ڵ㣬pos->nextΪ�գ����޷�����pos->next->next
	pos->next = tmp;
}
