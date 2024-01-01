#include "SList.h"


int main()
{
	SListNode* plist = NULL;

	printf("尾插\n");
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	printf("头插\n");
	SListPushFront(&plist, 10);
	SListPushFront(&plist, 20);
	SListPushFront(&plist, 30);
	SListPrint(plist);

	printf("尾删\n");
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);

	//printf("头删\n");
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLNode* pos = NULL;

	//printf("在1前插入666\n");
	//pos = SLTFinde(plist, 1);
	//SLTInsert(&plist, pos, 666);
	//SLTPrint(plist);

	//printf("在1前插入666\n");
	//pos = SLTFinde(plist, 1);
	//SLTInsert(&plist, pos, 666);
	//SLTPrint(plist);

	//printf("删除1\n");

	//pos = SLTFinde(plist, 1);
	//SLTErase(&plist, pos);
	//SLTPrint(plist);


	//SLTDestroy(&plist);

	return 0;
}