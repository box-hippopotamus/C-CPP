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
		printf("请选择\n");
		scanf("%d", &star);

		switch (star)
		{
		case 1:
			game();
			break;
		case 2:
			printf("正在退出游戏\n");
			break;
		default:
			printf("请在1或2中选择\n");
			again = 1;

		}

	}while (again);
	return 0;
}