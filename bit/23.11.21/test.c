#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int div(int x, int y)
{
	return x / y;
}

//ת�Ʊ�
int main()
{
	int choose = 0;

	int (*list[5]) (int, int) = { 0, add, sub, mul, div};

	printf("��ѡ��\n");
	printf("------------------\n");
	printf("------0.exit------\n");
	printf("------1.add------\n");
	printf("------2.sub------\n");
	printf("------3.mul------\n");
	printf("------4.div------\n");
	printf("------------------\n");

	scanf("%d", &choose);

	if (choose)
	{
		int x, y, num;
		printf("�������������\n");
		scanf("%d %d", &x, &y);
		switch (choose)
		{
			case 1:
				num = list[1](x, y);
				break;
			case 2:
				num = list[2](x, y);
				break;
			case 3:
				num = list[3](x, y);
				break;
			case 4:
				num = list[4](x, y);
				break;
		}
		printf("���Ϊ%d\n", num);
	}
	else
	{
		printf("�����˳�\n");
	}
	return 0;
}