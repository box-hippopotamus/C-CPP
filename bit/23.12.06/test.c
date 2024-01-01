#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Stdlib.h>
#include <math.h>
#include <stdbool.h>

//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//
//int maxDepth(struct TreeNode* root) 
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
//}


//
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
//{
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p && q)
//    {
//        if (p->val != q->val)
//        {
//            return false;
//        }
//
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
// 
//    }
//
//    return false;
//}


//
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
// 
//bool isUnivalTree(struct TreeNode* root) 
//{
//    if (root == NULL)
//        return true;
//
//    if (root->left && root->left->val != root->val
//        || root->right && root->right->val != root->val)
//    {
//        return false;
//    }
//
//    return isUnivalTree(root->right) && isUnivalTree(root->left);
//}


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PreOrder(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
        return;

    a[(*i)++] = root->val;
    PreOrder(root->left, a, i);
    PreOrder(root->right, a, i);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int n = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * n);
    int i = 0;
    returnSize = n;

    PreOrder(root, a, &i);

    return a;
}