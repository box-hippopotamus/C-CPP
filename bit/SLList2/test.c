#include "SList.h"


int main()
{
	SListNode* plist = NULL;

	printf("β��\n");
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	printf("ͷ��\n");
	SListPushFront(&plist, 10);
	SListPushFront(&plist, 20);
	SListPushFront(&plist, 30);
	SListPrint(plist);

	printf("βɾ\n");
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);

	//printf("ͷɾ\n");
	//SLTPopFront(&plist);
	//SLTPrint(plist);
	//SLTPopFront(&plist);
	//SLTPrint(plist);

	//SLNode* pos = NULL;

	//printf("��1ǰ����666\n");
	//pos = SLTFinde(plist, 1);
	//SLTInsert(&plist, pos, 666);
	//SLTPrint(plist);

	//printf("��1ǰ����666\n");
	//pos = SLTFinde(plist, 1);
	//SLTInsert(&plist, pos, 666);
	//SLTPrint(plist);

	//printf("ɾ��1\n");

	//pos = SLTFinde(plist, 1);
	//SLTErase(&plist, pos);
	//SLTPrint(plist);


	//SLTDestroy(&plist);

	return 0;
}