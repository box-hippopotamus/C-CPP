#include "LT.h"


int main()
{
	ListNode* phead = LTInt();

	ListPrint(phead);

	printf("β�����\n");
	ListPushBack(phead, 0);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListPushBack(phead, 6);
	ListPushBack(phead, 7);
	ListPushBack(phead, 8);
	ListPushBack(phead, 9);
	ListPrint(phead);

	printf("ͷ�����\n");
	ListPushFront(phead, 10);
	ListPushFront(phead, 20);
	ListPushFront(phead, 30);
	ListPushFront(phead, 40);
	ListPushFront(phead, 50);
	ListPushFront(phead, 60);
	ListPrint(phead);

	printf("βɾ����\n");
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	printf("ͷɾ����\n");
	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListNode* pos = NULL;
	pos = ListFind(phead, 5);
	printf("��5ǰ����123\n");
	ListInsert(pos, 123);
	ListPrint(phead);

	pos = ListFind(phead, 20);
	printf("��20ǰ����456\n");
	ListInsert(pos, 456);
	ListPrint(phead);

	pos = ListFind(phead, 2);
	printf("��2ǰ����789\n");
	ListInsert(pos, 789);
	ListPrint(phead);

	printf("ɾ��789\n");
	pos = ListFind(phead, 789);
	ListErase(pos);
	ListPrint(phead);

	printf("ɾ��456\n");
	pos = ListFind(phead, 456);
	ListErase(pos);
	ListPrint(phead);

	printf("ɾ��123\n");
	pos = ListFind(phead, 123);
	ListErase(pos);
	ListPrint(phead);


	return 0;
}