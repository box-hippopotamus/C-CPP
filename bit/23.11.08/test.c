#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main()
//{
//	//int score [5] = {1,2,3,4,5};
//	//printf("%p\n", &score[0]);
//	//printf("%p\n", &score[1]);
//	//printf("%p\n", &score[2]);
//	//printf("%p\n", &score[3]);
//	//printf("%p\n", &score[4]);
//	//printf("%p\n", arr);
//	//printf("%p\n", &arr);
//	//printf("%p\n", &arr[0]);
//
//
//
//
//
//
//
//
//	int* p = NULL;
//
//	return 0;
//}


#include <stdio.h>
int main()
{
	int arr[3][5] = { 0 };

	printf("%p\n", arr);
	printf("%p\n", (arr + 1));
	printf("%p\n", (arr + 2));




	return 0;
}