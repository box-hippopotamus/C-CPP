#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//struct TreeNode {
//    char data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//struct TreeNode* BuyTreeNode(int x)
//{
//    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    if (root == NULL)
//    {
//        perror("malloc fail!");
//        exit(-1);
//    }
//
//    root->data = x;
//    root->left = NULL;
//    root->right = NULL;
//    return root;
//}
//
//struct TreeNode* PreOrder(char* a, int* i)
//{
//    if (a[*i] != '#')
//    {
//        struct TreeNode* root = BuyTreeNode(a[(*i)++]);
//        root->left = PreOrder(a, i);
//        root->right = PreOrder(a, i);
//        return root;
//    }
//
//    (*i)++;
//    return NULL;
//}
//
//void InOrder(struct TreeNode* root)
//{
//    if (root == NULL)
//        return;
//
//    InOrder(root->left);
//    printf("%c ", root->data);
//    InOrder(root->right);
//}
//
//int main() {
//    char a[100] = { 0 };
//    while (scanf("%s", &a) != EOF) 
//    { 
//        int i;
//        struct TreeNode* root = PreOrder(a, &i);
//        InOrder(root);
//        printf("\n");
//    }
//    return 0;
//}



int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PostOrder(struct TreeNode* root, int* a, int* i)
{
    if (root == NULL)
        return;

    PostOrder(root->left, a, i);
    PostOrder(root->right, a, i);
    a[(*i)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    PostOrder(root, a, &i);

    return a;
}

//平衡二叉树
int TreeHeight(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}


bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    if (abs(TreeHeight(root->left) - TreeHeight(root->right)) <= 1)
    {
        return isBalanced(root->left) && isBalanced(root->right);
    }


    return false;
}

//对称二叉树

bool Symmetric(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
        return true;

    if (left && right && left->val == right->val)
    {
        return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
    }


    return false;
}


bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    return Symmetric(root->left, root->right);
}