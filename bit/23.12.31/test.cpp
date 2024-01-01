#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool IsLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	return false;
}

int dayOfYear(char* date) 
{
	int year, month, day;
	
	char* s = strtok(date, "-");
	year = atoi(s);

	s = strtok(NULL, "-");
	month = atoi(s);

	s = strtok(NULL, "-");
	day = atoi(s);

	int monthDay[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int ans = 0;

	for (int i = 0; i < month - 1; i++)
	{
		if (i == 1 && IsLeapYear(year))
		{
			ans += 1;
		}
		ans += monthDay[i];
	}

	ans += day;

	return ans;
}

int main()
{
	return 0;
}