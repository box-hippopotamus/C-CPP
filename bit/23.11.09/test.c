#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct st
{
	int a;
	int arr[];//���������Ա
};

int main()
{
	struct st* p = (struct st*)malloc(sizeof(struct st) + 10 * sizeof(int));
	//Ϊ�ṹ�忪�ٿռ䣬��Ϊ�������鿪�ٿռ���10��Ԫ��
	if (p == NULL)//��鿪�ٿռ��Ƿ�ɹ�
	{
		perror("malloc");
		return 1;
	}
	//Ϊ���������Ԫ�ظ�ֵ
	int i = 0;
	p->a = 100;

	for (i = 0; i < 10; i++)
	{
		p->arr[i] = i;
	}
	//�о����鳤�Ȳ������������飺
	struct st* ptr = realloc(p, sizeof(struct st) + 15 * sizeof(int));
	//����5��Ԫ�صĿռ�
	if (ptr == NULL)//��鿪�ٿռ��Ƿ�ɹ�
	{
		perror("realloc");
		return 1;
	}
	else
	{
		p = ptr;
		ptr = NULL;
	}
	//�Ժ������ٵ�5���ռ丳ֵ
	for (i = 10; i < 15; i++)
	{
		p->arr[i] = i;
	}

	//�ͷſռ�
	free(p);
	p = NULL;
	return 0;
}