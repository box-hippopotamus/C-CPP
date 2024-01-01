#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct test
{
	int i;
	int* a;
};

int main()
{
	//在栈区中定义结构体abc
	struct test abc;
	//在堆区创建柔性数组，指针返回给结构体的成员
	abc.a = (int*)malloc(10 * sizeof(int));

	free(abc.a);

	return 0;
}