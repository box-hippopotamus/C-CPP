#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

char f(char n)
{
	if ((n >= 87 && n <= 90) || (n >= 119 && n <= 122)) return(n - 22);
	else return(n + 4);
}

int main()
{
	char a[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%c", &a[i]);
		a[i] = f(a[i]);
	}
	for (i = 0; i < 5; i++)
		printf("%c", a[i]);
	return 0;
}