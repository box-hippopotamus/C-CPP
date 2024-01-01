#include "SeqList.h"

void test1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPushBack(&sl, 6);
	SLPrint(&sl);

	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40);
	SLPushFront(&sl, 50);
	SLPushFront(&sl, 60);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
		
	SLPopFront(&sl);
	SLPrint(&sl);

	SLInsert(&sl, 3, 100);
	SLPrint(&sl);

	SLInsert(&sl, 2, 100);
	SLPrint(&sl);

	SLErase(&sl, 3);
	SLPrint(&sl);

	SLErase(&sl, 5);
	SLPrint(&sl);

	SLDestroy(&sl);
}


int main()
{
	test1();

	return 0;
}