
#include "shenmin.h"

void menu()
{
	printf("------------------------\n");
	printf("---------1.game---------\n");
	printf("---------2.exit---------\n");
	printf("------------------------\n");
}
//��ʼ������
void initialize(char arr[lines][columns],int LINES, int COLUMNS, char set)
{
	int i, j;
	for(i=1;i < LINES;i++)
	{
		for(j=1;j < COLUMNS;j++)
		{
			arr[i][j] = set;
		}
	}
}
//��ӡ����
void putboard(char arr[lines][columns], int LINES, int COLUMNS)
{
	int i, j;
	printf("--------------------\n");
	for (i = 1; i < LINES; i++)
	{
		for (j = 1; j < COLUMNS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}
//������
void setmine(char arr[lines][columns], int LINES, int COLUMNS)
{
	int x, y;
	int count = easy_count;
	while (count)
	{
		x = rand() % LINES + 1;
		y = rand() % COLUMNS + 1;

		while (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}

//�Ų���
int addmine(char arr[lines][columns],int x,int y)
{
	int sum;
	sum = arr[x][y] +
		arr[x - 1][y] +
		arr[x + 1][y] +
		arr[x][y - 1] +
		arr[x][y + 1] +
		arr[x - 1][y - 1] +
		arr[x - 1][y + 1] +
		arr[x + 1][y - 1] +
		arr[x + 1][y + 1] -
		8 * '0';
		
	return sum;
}


void findmine(char arr[lines][columns])
{
	int x, y;
	int count = easy_count;
	do {
		printf("����������Ҫ�Ų����\n");
		scanf("%d %d", &x, &y);
		if (arr[x][y] == '0')
		{
			int count = '0' + addmine(arr[lines][columns],x,y);
			arr[x][y] = count + '0';
		}
		else if (arr[x][y] == '1')
		{
			printf("���ź����㱻ը����");
			break;
		}
	} while (count);
}

void game()
{
	char mine[lines][columns];
	char show[lines][columns];
	initialize(mine, lines, columns, '0');
	initialize(show, lines, columns, '*');

	setmine(mine, lines, columns);

	putboard(mine, lines, columns);
	putboard(show, lines, columns);

	findmine(mine[lines][columns]);

}


