#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void game()
{
	char show[ROWS][COLS];
	char mine[ROWS][COLS];

	renew_board(show, ROWS, COLS, '*');
	renew_board(mine, ROWS, COLS, '0');

	set_mine(mine, ROW, COL);

	//print_board(show, ROW, COL);
	//print_board(mine, ROW, COL);

	find_mine(show, mine, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("正在退出游戏\n");
			break;
		default:
			printf("请在0和1中选择\n");
		}
	} while (input);
	return 0;
}