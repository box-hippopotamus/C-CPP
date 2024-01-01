#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>



//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//
//};
//
//int TreeNodeSize(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//
//    return TreeNodeSize(root->left) + TreeNodeSize(root->right) + 1;
//}
//
//int* _preorderTraversal(struct TreeNode* root, int* a, int* pi)
//{
//    if (root == NULL)
//        return NULL;
//
//    a[(*pi)++] = root->val;
//    _preorderTraversal(root->left, a, pi);
//    _preorderTraversal(root->right, a, pi);
//
//    return root;
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    int n = TreeNodeSize(root);
//
//    int* a = (int*)malloc(sizeof(int) * n);
//    *returnSize = n;
//    int i = 0;
//    _preorderTraversal(root, a, &i);
//
//    return a;
//}


//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
// 
//struct TreeNode* invertTree(struct TreeNode* root) 
//{
//    if (root == NULL)
//        return NULL;
//
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//
//    invertTree(root->left);
//    invertTree(root->right);
//    return root;
//}



struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool _isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL && subRoot == NULL)
        return true;

    if (root && subRoot && root->val == subRoot->val)
        return true && _isSubtree(root->left, subRoot->left) && _isSubtree(root->right, subRoot->right);

    return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) 
{
    if (root == NULL)
        return false;

    if (root->val == subRoot->val)
    {
        if (_isSubtree(root, subRoot))
            return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}