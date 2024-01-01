#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
//菜单
void menu()
{
	printf("----------------------------------\n");
	printf("--------------1.game--------------\n");
	printf("--------------0.exit--------------\n");
	printf("----------------------------------\n");
}
//初始化
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
//打印
void print_board(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("-------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}//打印横坐标
	printf("\n");
	for (i = 1; i <= row; i++)//打印数组
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

//存放雷
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
		printf("请输入你想排查的坐标\n");
		scanf("%d %d", &x, &y);

		if (mine[x][y] == '0')
		{
			int back = sum(show, x, y);
			show[x][y] = back + '0';
			over++;
		}
		else if (mine[x][y] == '1')
		{
			printf("很遗恨你被炸死了\n");
			print_board(show, ROW, COL);
			break;
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
	if (over == row * col - easy_count)
	{
		printf("恭喜你，扫雷成功\n");
	}
}