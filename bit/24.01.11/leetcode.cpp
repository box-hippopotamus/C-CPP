#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addMinimum(char* word) 
{
	int ans = 0;
	char* prev = word;
	char* cur = word + 1;

	if (*prev == 'b')
		ans += 1;//bǰ����a
	else if (*prev == 'c')
		ans += 2;

	while (*prev != '\0')
	{
		if (*cur == 'a')
		{
			if (*prev == 'a')
				ans += 2;//����bc
			else if (*prev == 'b')
				ans += 1;//����c
		}
		else if (*cur == 'b')
		{
			if (*prev == 'b')
				ans += 2;//����ca
			else if (*prev == 'c')
				ans += 1;//����a
		}
		else if (*cur == 'c')
		{
			if (*prev == 'a')
				ans += 1;//����b
			else if (*prev == 'c')
				ans += 2;//����ab
		}
		else if (*cur == '\0')
		{
			if (*prev == 'a')
				ans += 2;
			else if (*prev == 'b')
				ans += 1;
		}
		prev++;
		cur++;
	}

	return ans;
}

int main()
{
	return 0;
}