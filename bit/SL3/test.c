#include "SeqList.h"


void test1(SeqList* ps) 
{
	SeqListPushFront(ps, 1);
	SeqListPushFront(ps, 2);
	SeqListPushFront(ps, 3);
	SeqListPushFront(ps, 4);
	SeqListPushFront(ps, 5);

}

void test2(SeqList* ps)
{
	SeqListPushBack(ps, 100);
	SeqListPushBack(ps, 200);
	SeqListPushBack(ps, 300);
	SeqListPushBack(ps, 400);
	SeqListPushBack(ps, 500);
}

void test3(SeqList* ps)
{
	SeqListPopFront(ps);
	SeqListPopFront(ps);
	SeqListPopFront(ps);

}

void test4(SeqList* ps)
{
	SeqListPopBack(ps);
	SeqListPopBack(ps);
	SeqListPopBack(ps);
}

void test5(SeqList* ps)
{
	SeqListInsert(ps, 2, 111);
	SeqListPrint(ps);
	SeqListInsert(ps, 1, 222);
	SeqListPrint(ps);
	SeqListInsert(ps, 4, 333);
	SeqListPrint(ps);
}

void test6(SeqList* ps)
{
	SeqListErase(ps, 1);
	SeqListPrint(ps);
	SeqListErase(ps, 5);
	SeqListPrint(ps);
	SeqListErase(ps, 0);
	SeqListPrint(ps);
}
int main()
{
	SeqList sl;

	SeqListInit(&sl);
	//Õ∑≤Â≤‚ ‘
	test1(&sl);
	SeqListPrint(&sl);

	//Œ≤≤Â≤‚ ‘
	test2(&sl);
	SeqListPrint(&sl);

	//Õ∑…æ≤‚ ‘
	test3(&sl);
	SeqListPrint(&sl);

	//Œ≤…æ≤‚ ‘
	test4(&sl);
	SeqListPrint(&sl);

	//pos≤Â»Î≤‚ ‘
	test5(&sl);
	SeqListPrint(&sl);

	//pos…æ≥˝≤‚ ‘
	test6(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
	return 0;
}