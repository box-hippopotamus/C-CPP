#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////int main()
////{
////	int x = 10;
////	int y = 0;
////	int a = 5;
////	int* p = &a;
////	y = x/*p ;/*pÖ¸Ïò³ýÊý*/
////
////	return 0;
////}
//
//
//int main()
//{
//	
//	int a = 'abc';
//
//	return 0;
//}

struct ListNode {
    int val;
    struct ListNode* next;
};
 
//struct ListNode* reverseList(struct ListNode* head) 
//{
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = head;
//
//
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = newhead;
//        newhead = cur;
//        cur = next;
//    }
//    return newhead;
//}


//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
// 
//
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) 
//{
//    struct ListNode* fast = pListHead;
//    struct ListNode* slow = pListHead;
//
//    while (k--)
//    {
//        if (fast == NULL)
//            return NULL;
//
//        fast = fast->next;
//    }
//
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//
//    return slow;
//}




//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
// 
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    struct ListNode* tail1 = headA;
//    struct ListNode* tail2 = headB;
//    int count1 = 0;
//    int count2 = 0;
//
//    while (tail1->next)
//    {
//        tail1 = tail1->next;
//        count1++;
//    }
//
//    while (tail2->next)
//    {
//        tail2 = tail2->next;
//        count2++;
//    }
//
//    if (tail1 != tail2)
//    {
//        return NULL;
//    }
//    int k = abs(count1 - count2);
//    struct ListNode* LongList = headA, * ShortList = headB;
//    if (count2 > count1)
//    {
//        LongList = headB;
//        ShortList = headA;
//    }
//
//    while (k--)
//    {
//        LongList = LongList->next;
//    }
//
//    while (LongList != ShortList)
//    {
//        LongList = LongList->next;
//        ShortList = ShortList->next;
//    }
//
//    return LongList;
//}


#include <stdbool.h>

//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};
// 
//bool hasCycle(struct ListNode* head) 
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//    return false;
//}





struct ListNode {
    int val;
    struct ListNode* next;
};
 
struct ListNode* detectCycle(struct ListNode* head) 
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            struct ListNode* p = head;

            while (slow != p)
            {
                slow = slow->next;
                p = p->next;
            }

            return p;
        }
    }

    return NULL;
}

struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            struct ListNode* meet = slow;

            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
        
    }
    
    return NULL;
}