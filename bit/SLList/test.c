#include "SList.h"

int main()
{

	SLNode* plist = NULL;
	printf("β��\n");
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	printf("ͷ��\n");
	SLTPushFront(&plist, 10);
	SLTPushFront(&plist, 20);
	SLTPushFront(&plist, 30);
	SLTPrint(plist);

	printf("βɾ\n");
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

	printf("ͷɾ\n");
	SLTPopFront(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTPrint(plist);

	SLNode* pos = NULL;

	printf("��1ǰ����666\n");
	pos = SLTFinde(plist, 1);
	SLTInsert(&plist, pos, 666);
	SLTPrint(plist);

	printf("��1ǰ����666\n");
    pos = SLTFinde(plist, 1);
	SLTInsert(&plist, pos, 666);
	SLTPrint(plist);

	printf("ɾ��1\n");
	pos = SLTFinde(plist, 1);
	SLTErase(&plist, pos);
	SLTPrint(plist);

	SLTDestroy(&plist);

	return 0;
}