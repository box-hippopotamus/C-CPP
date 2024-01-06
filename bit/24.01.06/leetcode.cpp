#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
 
int greatestCommonDivisor(int x, int y)
{
	int k = 0;
	while (k = x % y) {
		x = y;
		y = k;
	}

	return y;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) 
{
	struct ListNode* prev = head;
	struct ListNode* cur = head->next;

	while (cur)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = greatestCommonDivisor(cur->val, prev->val);
		node->next = cur;
		prev->next = node;

		prev = cur;
		cur = cur->next;
	}

	return head;
}

struct ListNode* create(int x)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

int main()
{
	struct ListNode* a = create(18); 
	struct ListNode* b = create(6);
	struct ListNode* c = create(10);
	struct ListNode* d = create(3);

	//a->next = b;
	//b->next = c;
	//c->next = d;

	struct ListNode* cur = a;

	while (cur)
	{
		printf("%d -> ", cur->val);
		cur = cur->next;
	}
	printf("\n");

	struct ListNode* newhead = insertGreatestCommonDivisors(a);

	cur = newhead;

	while (cur)
	{
		printf("%d -> ", cur->val);
		cur = cur->next;
	}


	return 0;
}