#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMaxRepetitions(char* s1, int n1, char* s2, int n2) {
    if (n1 == 0) {
        return 0;
    }

    int slen1 = strlen(s1);
    int slen2 = strlen(s2);

    int* s2_next_idxs = (int*)calloc(slen2 + 1, sizeof(int));

    int* s2_cnts = (int*)calloc(slen2 + 1, sizeof(int));

    int next_idx = 0;
    int cnt = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < slen1; j++)
        {
            if (s1[j] == s2[next_idx])
            {
                next_idx++;
            }
            if (next_idx == slen2)
            {
                next_idx = 0;
                cnt++;
            }
        }

        s2_next_idxs[i] = next_idx;
        s2_cnts[i] = cnt;

        for (int j = 0; j < i; j++)
        {
            if (s2_next_idxs[j] == s2_next_idxs[i])
            {
                int core_cnt = (s2_cnts[i] - s2_cnts[j]) * ((n1 - 1 - j) / (i - j));

                int pre_and_post_cnt = s2_cnts[j + ((n1 - 1 - j) % (i - j))];

                return (core_cnt + pre_and_post_cnt) / n2;
            }
        }
    }

    return s2_cnts[n1 - 1] / n2;
}
//int getMaxRepetitions(char* s1, int n1, char* s2, int n2)
//{
//	char* str1 = (char*)malloc(sizeof(char) * strlen(s1) * (n1 + 1));
//	strcpy(str1, s1);
//	for (int i = 0; i < n1 - 1; i++)
//	{
//		strcat(str1, s1);
//	}
//
//	char* str2 = (char*)malloc(sizeof(char) * strlen(s2) * (n2 + 1));
//	strcpy(str2, s2);
//	for (int i = 0; i < n2 - 1; i++)
//	{
//		strcat(str2, s2);
//	}
//
//	char* cur1 = str1;
//	char* cur2 = str2;
//	int contain = 0;
//
//	while (*cur1 != '\0')
//	{
//		if (*cur1 == *cur2)
//		{
//			cur2++;
//			if (*cur2 == '\0')
//			{
//				contain++;
//				cur2 = str2;
//			}
//		}
//		cur1++;
//	}
//
//	free(str1);
//	free(str2);
//	return contain;
//}

int main()
{
	char s1[] = "aaa";
	char s2[] = "aa";
	int n1 = 3;
	int n2 = 1;

	int ans = getMaxRepetitions(s1, n1, s2, n2);

	printf("%d", ans);

	return 0;
}