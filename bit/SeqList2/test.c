#include "SeqList.h"

void test()
{
	SL sl;
	SLInit(&sl);
	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPrint(&sl);

	SLPushBack(&sl, 10);
	SLPushBack(&sl, 20);
	SLPushBack(&sl, 30);
	SLPushBack(&sl, 40);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPrint(&sl);

	SLErase(&sl, 2);
	SLPrint(&sl);
	SLErase(&sl, 3);
	SLPrint(&sl);

	SLInsert(&sl, 1, 100);
	SLPrint(&sl);
	SLInsert(&sl, 0, 200);
	SLPrint(&sl);
	SLInsert(&sl, 2, 300);
	SLPrint(&sl);
	SLInsert(&sl, 5, 500);
	SLPrint(&sl);
	SLInsert(&sl, 7, 1000);
	SLPrint(&sl);


	SLDestroy(&sl);
}

int main()
{
	test();
}