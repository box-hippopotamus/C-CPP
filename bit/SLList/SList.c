#include "SList.h"

//输出链表
void SLTPrint(SLNode* phead)
{
	//不断言，phead可以为空
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->",cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建新节点 
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


//尾插
void SLTPushBack(SLNode** pphead, SLNDataType x)
 {
	assert(pphead);
	//注意此处创建的newnode，tail，pphead都是临时变量，函数结束时都会销毁
	//但是malloc开辟的空间与其存储的数据保留并且利用传址调用，将上一节点的值也改变
	SLNode* newnode = CreateNode(x);
	if (*pphead == NULL)//此处需要改变phead，所以要传入pphead
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)//找尾
		{
			tail = tail->next;
		}
		tail->next = newnode;//此处要改变一个结构体中的next成员，由于tail已经是结构体的地址，访问后就可以直接修改next的值
	}
}

//头插
void SLTPushFront(SLNode** pphead, SLNDataType x)
{
	assert(pphead);
	SLNode* newnode = CreateNode(x);
	newnode->next = *pphead;
	*pphead = newnode; 	
}

//尾删
void SLTPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{//单独讨论一个元素的作用：当销毁掉第一个元素后，要将phead置空
		free(*pphead);
		(*pphead) = NULL;	
	}
	else
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		//？？？？
		//注意：此处prev不能初始化为*pphead，否则，若链表只有一个元素，两者都是pphead，free掉tail指向的元素后,prev指向的就是野指针
		//？？？？
		while (tail->next != NULL) 
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);//此处无需置空tail，因为出了函数tail自动被销毁
		tail = NULL;
		prev->next = NULL;  
	}
}

////尾删2
//void SLTPopBack(SLNode** pphead)
//{
//	assert(*pphead);
//
//	SLNode* tail = *pphead;
//	SLNode* prev = NULL;
//	//？？？？
//	//注意：此处prev不能初始化为*pphead，否则，若链表只有一个元素，两者都是pphead，free掉tail指向的元素后,prev指向的就是野指针
//	//？？？？
//	while (tail->next != NULL)
//	{
//		prev = tail;
//		tail = tail->next;
//	}
//	free(tail);//此处无需置空tail，因为出了函数tail自动被销毁
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

////尾删3
//void SLTPopBack(SLNode** pphead)
//{
//	assert(*pphead);
//	if ((*pphead)->next == NULL)
//	{//单独讨论一个元素的作用：当销毁掉第一个元素后，要将phead置空
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
//		free(tail->next);//free掉的是next指向的下一个节点
//		tail->next = NULL;//置空的是当前节点的next
//	}
//}

//头删
void SLTPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	 
	SLNode* tmp = (*pphead)->next;
	free(*pphead);
	*pphead = tmp;
	//此处无需额外讨论只有一个元素情况，当只有一个元素，tmp会被赋值为NULL
	//然后*pphead也会随着tmp被赋值为NULL
}

//查找
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

//在pos位置前插入一个节点
void SLTInsert(SLNode** pphead, SLNode* pos, SLNDataType x)
{//由于单向链表无法找到上一个元素的地址，所以要再传入一个头指针
	assert(pphead);
	//assert(*pphead);//无需断言，此处为空说明链表没有元素，那就是头插
	//assert(pos);//无需断言，当*pphead，即phead为空，没有元素的情况下，在pos前插入节点相当于在NULL前插入
	assert( (pos && *pphead) || (!pos && !*pphead));//要么都是空，要么都不是空

	if (*pphead == pos)
	{
		//头插
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;//找到目标位置前一个节点
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLNode* newnode = CreateNode(x);
		prev->next = newnode;
		newnode->next = pos; 
	}
}

//不使用头指针在pos前插入：
void SLTInsert2(SLNode* pos, SLNDataType x)
{
	assert(pos);
	SLTInsertAfter(pos, x);//在pos后插入

	pos->next->val = pos->val;//交换pos与pos后新建节点的数据，相当于在pos前插入
	pos->val = x;
}



//删除pos位置
void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if (*pphead == pos)//单独讨论只有一个元素，防止空指针
	{
		//头删
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)//如果不分开讨论第一个元素，此处prev永远找不到pos，死循环后崩溃
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//销毁顺序表
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


//在pos后插入
void SLTInsertAfter(SLNode* pos, SLNDataType x) 
{
	assert(pos);
	SLNode* newnode = CreateNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}

//在pos后删除
void SLTErasetAfter(SLNode* pos)
{
	assert(pos);

	SLNode* tmp = pos->next->next;
	free(pos->next);//如果pos是尾部节点，pos->next为空，就无法访问pos->next->next
	pos->next = tmp;
}
