#define _CRT_SECURE_NO_WARNINGS 1

#include "shenmin.h"


int main()
{
	int star,again;
	srand((unsigned int)time(NULL));

	do
	{
		again = 0;
		menu();
		printf("��ѡ��\n");
		scanf("%d", &star);

		switch (star)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�����˳���Ϸ\n");
			break;
		default:
			printf("����1��2��ѡ��\n");
			again = 1;

		}

	}while (again);
	return 0;
}