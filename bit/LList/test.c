#include "List.h"

int main()
{
	LTNode* phead = LTInit();

	//尾插
	printf("尾插：\n");
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	//头插
	printf("头插：\n");
	LTPushFront(phead, 10);
	LTPushFront(phead, 20);
	LTPushFront(phead, 30);
	LTPushFront(phead, 40);
	LTPushFront(phead, 50);
	LTPrint(phead);
	//尾删
	printf("尾删：\n");
	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPrint(phead);
	//头删
	printf("头删：\n");
	LTPopFront(phead);
	LTPopFront(phead);
	LTPrint(phead);

	LTNode* pos = NULL;

	printf("1前插入111\n");
	pos = LTFind(phead, 1);
	LTInsert(pos, 111);
	LTPrint(phead);

	printf("30前插入222\n");
	pos = LTFind(phead, 30);
	LTInsert(pos, 222);
	LTPrint(phead);

	printf("20前插入333\n");
	pos = LTFind(phead, 20);
	LTInsert(pos, 333);
	LTPrint(phead);



	return 0;
}