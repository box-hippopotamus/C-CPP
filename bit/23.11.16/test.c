#define _CRT_SECURE_NO_WARNINGS 1




struct ListNode {
    int val;
    struct ListNode* next;
};
#include <stdio.h>
#include <stdlib.h>

//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//    struct ListNode* cur = head;
//
//    struct ListNode* newhead = malloc(sizeof(struct ListNode));
//    struct ListNode* tail = newhead;
//    newhead->next = NULL;
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        if (cur->val != val)
//        {
//            //尾插
//            tail->next = cur;
//            cur->next = NULL;
//            tail = tail->next;
//        }
//        cur = next;
//        if (next)
//            next = next->next;
//    }
//
//    return newhead->next;
//}

//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//    struct ListNode* cur = head;
//    struct ListNode* prev = NULL;
//
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            struct ListNode* tmp = cur->next;
//            free(cur);
//            if (prev)
//                prev->next = tmp;
//            else
//                head = tmp;
//            cur = tmp;
//        }
//        else
//        {
//            if (prev)
//            {
//                prev->next = cur;
//                prev = cur;
//                cur = cur->next;
//            }
//            else
//            {
//                head = cur;
//                prev = head;
//                cur = cur->next;
//            }
//        }
//    }
//    return head;
//}

//struct ListNode* reverseList(struct ListNode* head) 
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//
//    struct ListNode* cur = head;
//    struct ListNode* next = NULL;
//    struct ListNode* prev = NULL;
//
//    while (cur)
//    {
//        next = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = next;
//    }
//
//    return prev;
//}

//倒数第k节点
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) 
{
    if (pListHead == NULL)
        return NULL;
    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;

    while (k--)
    {
        fast = fast->next;
        if (fast == NULL)
            return NULL;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}
//环形链表
struct ListNode* detectCycle(struct ListNode* head) 
{
    if (head == NULL)
        return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != slow)
    {
        if (fast->next == NULL)
            return NULL;

        fast = fast->next->next;
        slow = slow->next;
    }

    struct ListNode* str = head;

    while (str != slow)
    {
        str = str->next;
        slow = slow->next;
    }

    return str;
}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (!(headA && headB))
        return NULL;

    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int countA = 0;
    int countB = 0;

    while (tailA->next)
    {
        tailA = tailA->next;
        countA++;
    }

    while (tailB->next)
    {
        tailB = tailB->next;
        countB++;
    }

    if (tailA == tailB)
    {
        struct ListNode* big = headB;
        struct ListNode* small = headA;
        int num = countB - countA;

        if (countA > countB)
        {
            big = headA;
            small = headB;
            num = countA - countB;
        }
        while (num--)
        {
            big = big->next;
        }

        while (big != small)
        {
            big = big->next;
            small = small->next;
        }
        return big;
    }

    return NULL;
}

//int main()
//{
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//    head->val = 7;
//    n1->val = 7;
//    n2->val = 7;
//    n3->val = 7;
//  /*  n4->val = 4;
//    n5->val = 5;
//    n6->val = 6;*/
//
//    head->next = n1;
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = NULL;
//    //n4->next = n5;
//    //n5->next = n6;
//    //n6->next = NULL;
//
//    removeElements(head,7);
//
//    return 0;
//}