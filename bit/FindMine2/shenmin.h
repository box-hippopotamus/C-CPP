#define _CRT_SECURE_NO_WARNINGS 1

#define line 9
#define column 9
#define lines line+2
#define columns column+2
#define easy_count 10

#include <stdio.h>

void menu();
void initialize(char arr[lines][columns], int LINES, int COLUMN, char set);
void findmine(char arr[lines][columns]);
void putboard(char arr[lines][columns], int LINES, int COLUMNS);
void game();
void setmine(char arr[lines][columns], int LINES, int COLUMNS);
int addmine(char arr[lines][columns], int x, int y);