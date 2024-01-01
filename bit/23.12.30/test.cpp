#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;

	return false;
}

char* dayOfTheWeek(int day, int month, int year) 
{
	const char* week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	int Month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int daySum = 0;

	daySum = (year - 1971) * 365 + (year - 19668) / 4;

	for (int i = 0; i < month - 1; i++)
	{
		if (isLeapYear(year) && i == 1)
			daySum += 1;

		daySum += Month[i];
	}
	daySum += day - 1;

	int weekIndex = (daySum + 5) % 7 - 1;

	return (char*)week[weekIndex];
}

int main()
{

	return 0;
}