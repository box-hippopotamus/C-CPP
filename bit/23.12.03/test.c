#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct student
{
	char name[10];
	int num;
	int age;
	char addr[15];
};

void save(struct student* student)
{
	FILE* pf = fopen("stu_list.txt", "w");
	if (pf == NULL)
	{
		perror("fopen fail!");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		scanf("%s %d %d %s", &student[i].name, &student[i].num, &student[i].age, &student[i].addr);
	}

	for (int i = 0; i < 3; i++)
	{
		fprintf(pf, "%s %d %d %s\n", student[i].name, student[i].num, student[i].age, student[i].addr);
	}

	fclose(pf);
}

void load(struct student* student)
{
	FILE* pf = fopen("stu_list.txt", "r");
	if (pf == NULL)
	{
		perror("fopen fail!");
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		fscanf(pf, "%s %d %d %s\n", &student[i].name, &student[i].num, &student[i].age, &student[i].addr);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s %d %d %s\n", &student[i].name, student[i].num, student[i].age, &student[i].addr);
	}

	fclose(pf);
}

int main() 
{
	struct student student[3];

	save(student);
	load(student);
	return 0;
}