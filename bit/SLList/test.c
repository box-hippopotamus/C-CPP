#include "SList.h"

int main()
{

	SLNode* plist = NULL;
	printf("尾插\n");
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	printf("头插\n");
	SLTPushFront(&plist, 10);
	SLTPushFront(&plist, 20);
	SLTPushFront(&plist, 30);
	SLTPrint(plist);

	printf("尾删\n");
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

	printf("头删\n");
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);

	SLNode* pos = NULL;

	printf("在1前插入666\n");
	pos = SLTFinde(plist, 1);
	SLTInsert(&plist, pos, 666);
	SLTPrint(plist);

	printf("在1前插入666\n");
    pos = SLTFinde(plist, 1);
	SLTInsert(&plist, pos, 666);
	SLTPrint(plist);

	printf("删除1\n");
	pos = SLTFinde(plist, 1);
	SLTErase(&plist, pos);
	SLTPrint(plist);

	SLTDestroy(&plist);

	return 0;
}