#include "SeqList.h"

void Sltest()
{
	SL sl;//�����ṹ��
	SLInit(&sl);//��ʼ��˳���
	//˳������
	SLPushBack(&sl, 1);//����β��1
	SLPushBack(&sl, 2);//1 2
	SLPushBack(&sl, 3);//1 2 3
	SLPushBack(&sl, 4);//1 2 3 4
	SLPrint(&sl);
	//����ͷ��
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