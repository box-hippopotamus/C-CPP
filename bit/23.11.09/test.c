#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct st
{
	int a;
	int arr[];//柔性数组成员
};

int main()
{
	struct st* p = (struct st*)malloc(sizeof(struct st) + 10 * sizeof(int));
	//为结构体开辟空间，并为柔性数组开辟空间存放10个元素
	if (p == NULL)//检查开辟空间是否成功
	{
		perror("malloc");
		return 1;
	}
	//为柔性数组的元素赋值
	int i = 0;
	p->a = 100;

	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	//感觉数组长度不够，增长数组：
	struct st* ptr = realloc(p, sizeof(struct st) + 15 * sizeof(int));
	//增加5个元素的空间
	if (ptr == NULL)//检查开辟空间是否成功
	{
		perror("realloc");
		return 1;
	}
	else
	{
		p = ptr;
		ptr = NULL;
	}
	//对后续开辟的5个空间赋值
	for (i = 10; i < 15; i++)
	{
		p->arr[i] = i;
	}

	//释放空间
	free(p);
	p = NULL;
	return 0;
}