
#include "LinkList.h"

//输出链表
void SLTPrint(LLNode* phead)
{
	//不断言，phead可以为空
	LLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建节点
LLNode* CreateNode(LLNDataType x)
{
	//创建空间，并用指针newnode维护此节点
	LLNode* newnode = (LLNode*)malloc(sizeof(LLNode));
	if (newnode == NULL)//确保开辟成功
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->val = x;//将val赋值为指定元素
	newnode->next = NULL;//将此节点的指针置NULL
	return newnode;//将此节点的指针返回
}

//头插
void LLTPushFront(LLNode** pphead, LLNDataType x)
{
	assert(pphead);//确保指针有效性
	LLNode* newnode = CreateNode(x);//接收函数创建的节点的指针
	newnode->next = *pphead;//先将*pphead的值赋给newnode->next
	*pphead = newnode; 	//再将newnode的地址赋给*pphead
}

//尾插
void LLTPushBack(LLNode** pphead, LLNDataType x)
{
	assert(pphead);//确保指针有效性

	LLNode* newnode = CreateNode(x);//创建节点
	if (*pphead == NULL)//此处需要改变phead，所以要传入pphead
	{
		*pphead = newnode;//条件成立，修改phead
	}
	else
	{
		LLNode* tail = *pphead;//创建临时变量
		while (tail->next != NULL)//找尾
		{
			tail = tail->next;
		}
		tail->next = newnode;
		//将尾节点的next指针成员指向新节点，此后新节点就是新的尾节点了
	}
}

//头删
void LLTPopFront(LLNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	LLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
}

//尾删
void LLTPopBack(LLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)//当第一个节点的next为空，说明此链表只有一个节点。
	{//单独讨论一个元素的作用：当销毁掉第一个元素后，要将phead置空
		free(*pphead);//free头节点
		(*pphead) = NULL;	//置空phead
	}
	else
	{
		LLNode* tail = *pphead;//最后指向尾部的指针
		LLNode* prev = NULL;//最后指向尾节点前一个节点的指针

		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);//free掉原先尾节点
		tail = NULL;//养成free后置空的习惯，避免野指针。
		prev->next = NULL;  //将原先存住的倒数第二个节点的next置空
	}
}

//查找
LLNode* LLTFinde(LLNode* phead, LLNDataType x)
{
	assert(phead);

	LLNode* cur = phead;
	while (cur)//此循环用于遍历链表
	{
		if (cur->val == x)//条件成立，说明找到节点，返回指针
		{
			return cur;
		}

		cur = cur->next;
	}
	return NULL;
}

//在pos位置前插入一个节点
void LLTInsert(LLNode** pphead, LLNode* pos, LLNDataType x)
{//由于单向链表无法找到上一个元素的地址，所以要再传入一个头指针
	assert(pphead);
	assert((pos && *pphead) || (!pos && !*pphead));//要么都是空，要么都不是空

	if (*pphead == pos)
	{
		//if成立，说明为空链表，直接进行头插
		LLTPushFront(pphead, x);
	}
	else
	{
		LLNode* prev = *pphead;//找到目标位置前一个节点
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		LLNode* newnode = CreateNode(x);//此处的赋值顺序先前分析过
		prev->next = newnode;
		newnode->next = pos;
	}
}

//不使用头指针在pos前插入：
void LLTInsert2(LLNode* pos, LLNDataType x)
{
	assert(pos);
	LLTInsertAfter(pos, x);//在pos后插入

	pos->next->val = pos->val;//交换pos与pos后新建节点的数据，相当于在pos前插入
	pos->val = x;
}

//在pos后插入
void LLTInsertAfter(LLNode* pos, LLNDataType x)
{
	assert(pos);
	LLNode* newnode = CreateNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//在pos后删除
void LLTErasetAfter(LLNode* pos)
{
	assert(pos);
	assert(pos->next);

	LLNode* tmp = pos->next->next;//利用tmp存储pos的下下个节点
	free(pos->next);//释放pos节点的下一个节点
	pos->next = tmp;//将pos->next指向下下个节点
}

//删除pos位置
void LLTErase(LLNode** pphead, LLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)//单独讨论只有一个元素情况，防止空指针
	{
		//头删
		LLTPopFront(pphead);
	}
	else
	{
		LLNode* prev = *pphead;
		while (prev->next != pos)//如果不分开讨论第一个元素，此处prev永远找不到pos，死循环后崩溃
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//销毁链表
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