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
	//��ջ���ж���ṹ��abc
	struct test abc;
	//�ڶ��������������飬ָ�뷵�ظ��ṹ��ĳ�Ա
	abc.a = (int*)malloc(10 * sizeof(int));

	free(abc.a);

	return 0;
}