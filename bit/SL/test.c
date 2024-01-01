#include "SeqList.h"

void Sltest()
{
	SL sl;//创建结构体
	SLInit(&sl);//初始化顺序表
	//顺序表操作
	SLPushBack(&sl, 1);//测试尾插1
	SLPushBack(&sl, 2);//1 2
	SLPushBack(&sl, 3);//1 2 3
	SLPushBack(&sl, 4);//1 2 3 4
	SLPrint(&sl);
	//测试头插
	SLPushBack(&sl, 5);//5 1 2 3 4
	SLPushBack(&sl, 6);//6 5 1 2 3 4
	SLPushBack(&sl, 7);//7 6 5 1 2 3 4
	SLPrint(&sl);


	SLDestroy(&sl);
}

int main()
{
	Sltest();
	return 0;
}