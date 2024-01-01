#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
 

struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct Node* cur = head;
    struct Node* next = NULL;

    while (cur)
    {

        next = cur->next;
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->random = NULL;
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = next;
    }

    cur = head;
    struct Node* copynode = NULL;

    while (cur)
    {
        copynode = cur->next;
        if (cur->random)
            copynode->random = cur->random->next;
        else
            copynode->random = cur->random;
        cur = cur->next->next;
    }

    cur = head;
    struct Node* newhead = NULL;

    while (cur)
    {
        if (newhead == NULL)
        {
            newhead = cur->next;
        }

        if (cur && cur->next)
        {
            next = cur->next->next;
            copynode = cur->next;
            if (next)
            {
                copynode->next = next->next;
            }
            cur->next = next;
            cur = next;
        }
    }

    return newhead;
}


int main()
{

	return 0;
}