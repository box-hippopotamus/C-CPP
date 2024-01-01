#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	FILE* p=fopen("C:\\Users\\ºÎê¿Òæ\\Desktop\\test.txt", "r");

	if (p == NULL)
	{
		perror("fopen");

		return 1;
	}

	return  0;
};