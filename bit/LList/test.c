#include "List.h"

int main()
{
	LTNode* phead = LTInit();

	//β��
	printf("β�壺\n");
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPushBack(phead, 5);
	LTPrint(phead);
	//ͷ��
	printf("ͷ�壺\n");
	LTPushFront(phead, 10);
	LTPushFront(phead, 20);
	LTPushFront(phead, 30);
	LTPushFront(phead, 40);
	LTPushFront(phead, 50);
	LTPrint(phead);
	//βɾ
	printf("βɾ��\n");
	LTPopBack(phead);
	LTPopBack(phead);
	LTPopBack(phead);
	LTPrint(phead);
	//ͷɾ
	printf("ͷɾ��\n");
	LTPopFront(phead);
	LTPopFront(phead);
	LTPrint(phead);

	LTNode* pos = NULL;

	printf("1ǰ����111\n");
	pos = LTFind(phead, 1);
	LTInsert(pos, 111);
	LTPrint(phead);

	printf("30ǰ����222\n");
	pos = LTFind(phead, 30);
	LTInsert(pos, 222);
	LTPrint(phead);

	printf("20ǰ����333\n");
	pos = LTFind(phead, 20);
	LTInsert(pos, 333);
	LTPrint(phead);



	return 0;
}