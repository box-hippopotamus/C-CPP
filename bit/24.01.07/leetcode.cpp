#define _CRT_SECURE_NO_WARNINGS 1

#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine)
{
	int ranSize = strlen(ransomNote);
	int magSize = strlen(magazine);

	if (ranSize > magSize)
		return false;

	int ansArr[26] = { 0 };

	char* cur = magazine;

	while (*cur != '\0')
	{
		ansArr[*cur - 97]++;
		cur++;
	}

	cur = ransomNote;

	while (*cur != '\0')
	{
		ansArr[*cur - 97]--;
		cur++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (ansArr[i] < 0)
			return false;
	}

	return true;
}

int main()
{
	char arr1[] = "az";
	char arr2[] = "aegz";

	char* a = arr1;
	char* b = arr2;

	bool ans = canConstruct(a, b);

	printf("%d", ans);

	return 0;
}