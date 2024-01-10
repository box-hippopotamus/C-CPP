#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minLength(char* s)
{
	int ans = strlen(s);
	char stack[strlen(s)];
	int top = 0;

	char* cur = s;

	while (*cur != '\0')
	{
		if (top == 0)
		{
			stack[top++] = *cur;
			cur++;
			continue;
		}

		if (*cur == 'B' && stack[top - 1] == 'A'
			|| *cur == 'D' && stack[top - 1] == 'C')
		{
			top--;
			ans = ans - 2;
		}
		else
		{
			stack[top++] = *cur;
		}
		cur++;
	}

	return ans;
}

int main()
{

	char arr[] = "ABFCACDB";

	char* s = arr;
	minLength(s);
	return 0;
}