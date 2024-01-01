#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
//�˵�
void menu()
{
	printf("----------------------------------\n");
	printf("--------------1.game--------------\n");
	printf("--------------0.exit--------------\n");
	printf("----------------------------------\n");
}
//��ʼ��
void renew_board(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//��ӡ
void print_board(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("-------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}//��ӡ������
	printf("\n");
	for (i = 1; i <= row; i++)//��ӡ����
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

//�����
void set_mine(char board[ROWS][COLS], int row,int col)
{
	int count = easy_count;
	while(count)
	{
		int x = rand() % col + 1;
		int y = rand() % row + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int sum(char board[ROWS][COLS], int x, int y)
{
	int num = board[x + 1][y] +
		board[x - 1][y] +
		board[x][y + 1] +
		board[x][y - 1] +
		board[x + 1][y + 1] +
		board[x - 1][y - 1] +
		board[x - 1][y + 1] +
		board[x + 1][y - 1] - 8 * '0';
	return num;
}


void find_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x, y;
	int over = 0;
	int count = easy_count;

	while (over < row * col - easy_count)
	{
		print_board(show, ROW, COL);
		printf("�����������Ų������\n");
		scanf("%d %d", &x, &y);

		if (mine[x][y] == '0')
		{
			int back = sum(show, x, y);
			show[x][y] = back + '0';
			over++;
		}
		else if (mine[x][y] == '1')
		{
			printf("���ź��㱻ը����\n");
			print_board(show, ROW, COL);
			break;
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
	if (over == row * col - easy_count)
	{
		printf("��ϲ�㣬ɨ�׳ɹ�\n");
	}
}