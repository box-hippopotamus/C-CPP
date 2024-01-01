#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int isWinner(int* player1, int player1Size, int* player2, int player2Size)
{
	int score1 = 0;
	int score2 = 0;

	for (int i = 0; i < player1Size; i++)
	{
		if (i == 0)
			score1 += player1[0];
		else if (i == 1)
		{
			score1 += player1[i - 1] == 10 ? 2 * player1[i] : player1[i];
		}
		else
		{
			score1 += player1[i - 1] == 10 || player1[i - 2] == 10 ? 2 * player1[i] : player1[i];
		}
	}

	for (int i = 0; i < player2Size; i++)
	{
		if (i == 0)
			score2 += player2[0];
		else if (i == 1)
		{
			score2 += player2[i - 1] == 10 ? 2 * player2[i] : player2[i];
		}
		else
		{
			score2 += player2[i - 1] == 10 || player2[i - 2] == 10 ? 2 * player2[i] : player2[i];
		}
	}

	return score1 == score2 ? 0 : score1 < score2 ? 2 : 1;
}


int main()
{


	return 0;
}