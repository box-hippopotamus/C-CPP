#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_count 10

void menu();
void game();
void renew_board(char board[ROWS][COLS], int rows, int cols, char set);
void set_mine(char board[ROWS][COLS], int row, int col);
void print_board(char board[ROWS][COLS], int row, int col);
int sum(char board[ROWS][COLS], int x, int y);
void find_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);