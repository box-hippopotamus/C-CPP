
#include "Queue.h"


//------------------------------------------------------------------------------------------//
//伪造一颗树
TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}


TreeNode* CreateTree()
{
	TreeNode* node1 = BuyTreeNode(1);
	TreeNode* node2 = BuyTreeNode(2);
	TreeNode* node3 = BuyTreeNode(3);
	TreeNode* node4 = BuyTreeNode(4);
	TreeNode* node5 = BuyTreeNode(5);
	TreeNode* node6 = BuyTreeNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

//------------------------------------------------------------------------------------------//
//前序遍历
void PrevOrder(TreeNode* root)
{
	if (root == NULL)//为空直接返回
	{
		return;
	}

	printf("%d ", root->data);//遍历根
	PrevOrder(root->left);//遍历左子树
	PrevOrder(root->right);//遍历右子树
}

//中序遍历
void InOrder(TreeNode* root)
{
	if (root == NULL)//为空直接返回
	{
		return;
	}

	InOrder(root->left);//遍历左子树
	printf("%d ", root->data);//遍历根
	PrevOrder(root->right);//遍历右子树
}

//后序遍历
void PostOrder(TreeNode* root)
{
	if (root == NULL)//为空直接返回
	{
		return;
	}

	PostOrder(root->left);//遍历左子树
	PostOrder(root->right);//遍历右子树
	printf("%d ", root->data);//遍历根
}

//层序遍历
void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int LevelSize = 1;
	//一层一层出数据
	while (!QueueEmpty(&q))
	{
		while (LevelSize != 0)
		{
			TreeNode* front = QueueFront(&q);
			QueuePop(&q);

			printf("%d ", front->data);

			if (front->left)
				QueuePush(&q, front->left);
			if (front->right)
				QueuePush(&q, front->right);
			LevelSize--;
		}
		printf("\n");
		LevelSize = QueueSize(&q);
	}
	
	QueueDestroy(&q);
}

//求树的节点数目
int TreeSize(TreeNode* root)
{
	//if (root == NULL)//为空直接返回
	//{
	//	return 0;
	//}

	//int count = 1 + TreeSize(root->right) + TreeSize(root->left);

	//return count;
	//-----------------------------------------------//
	//优化：

	return root == NULL ? 0 : 1 + TreeSize(root->right) + TreeSize(root->left);
}

//求树的叶子节点数目
int TreeLeafSize(TreeNode* root)
{
	if (root == NULL)//为空直接返回
	{
		return 0;
	}

	if (TreeLeafSize(root->left) + TreeLeafSize(root->right) == 0)
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right) + 1;
	}
	else
	{
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}

	//-----------------------------------------------//
	//优化： 

	if (root == NULL)//为空直接返回
	{
		return 0;
	}

	int count = TreeLeafSize(root->left) + TreeLeafSize(root->right);
	return count == 0 ? count + 1 : count;

	//-----------------------------------------------//
	//航哥版本：
	// 
	//为空直接返回
	if (root == NULL)
		return 0;

	//左右都为空，说明为叶子，记录此叶子，返回1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//既不是空,也不是叶子，返回目前节点记录到的总叶子数目
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


//求树的高度 
int TreeHeight(TreeNode* root)
{
	if (root == NULL)//为空直接返回
	{
		return 0;
	}

	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

//求第k层节点个数
int TreeLevlk(TreeNode* root,int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;
	else
		return TreeLevlk(root->left, k - 1) + TreeLevlk(root->right, k - 1);
}

//查找值为x的节点
TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	TreeNode* p = TreeFind(root->left, x);
	if (p)
		return p;

	p = TreeFind(root->right, x);
	if (p)
		return p;

	return NULL;
}

//通过前序遍历的数组构建二叉树
TreeNode* TreeCreate(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	root->data = a[(*pi)++];
	 
	root->left = TreeCreate(a, pi);
	root->right = TreeCreate(a, pi);

	return root;
}

//判断一棵树是不是完全二叉树
bool LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{

		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;

		QueuePush(&q, front->left);
		QueuePush(&q, front->right);

	}

	//前面遇到空后，若后面还有非空，就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)//非空
			return false;
	}
	QueueDestroy(&q);

	return true;
}

//销毁树
void DestroyTree(TreeNode* root)
{
	if (root == NULL)
		return;
	DestroyTree(root->left);
	DestroyTree(root->right);
	free(root);
}

int main()
{
	TreeNode* root = CreateTree();

	LevelOrder(root);
	

	return 0;
}


//----------------------------------------------------------------------------------------------------------------//
////单值二叉树
//
//#include <stdbool.h>
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
// 
//bool isUnivalTree(struct TreeNode* root) 
//{
//	if (root == NULL)
//		return true;
//
//	if (root->left != NULL && root->val != root->left->val)
//	{
//		return false;
//	}
//
//	if (root->right != NULL && root->val != root->right->val)
//	{
//		return false;
//	}
//
//	//if (isUnivalTree(root->left) && isUnivalTree(root->right))
//	//	return true;
//	//else
//	//	return false;
//
//	//-----------------------------------------------//
//	return (isUnivalTree(root->left) && isUnivalTree(root->right));
//}
//
////------------------------------------------------------------------------------------//
////相同的树
//
//#include <stdbool.h>
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p != NULL && q != NULL)
//	{
//		if (p->val != q->val)
//			return false;
//
//		return isSameTree(p->left, q->left) 
//			&& isSameTree(p->right, q->right);
//	}
//
//	if (p == NULL && q == NULL)
//		return true;
//
//	return false;
//}
//
////------------------------------------------------------------------------------------//
////前序遍历
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//int TreeSize(struct TreeNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void preOrder(struct TreeNode* root, int* a, int* pi)
//{
//	if (root == NULL)
//		return;
//
//	a[(*pi)++] = root->val;
//
//	preOrder(root->left, a, pi);
//	preOrder(root->right, a, pi);
//}
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) 
//{ 
//	int n = TreeSize(root);
//	int* a = (int*)malloc(sizeof(int) * n);
//	*returnSize = n;
//
//	int i = 0;
//	preOrder(root, a, &i);
//
//	return a;
//}
//
////------------------------------------------------------------------------------------//
////对称二叉树
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//bool isTree(struct TreeNode* p, struct TreeNode* q)
//{
//
//	if (p == NULL && q == NULL)
//		return true;
//
//	if (p != NULL && q != NULL )
//	{
//		if (p->val != q->val)
//			return false;
//
//		return isTree(p->left, q->right)
//			&& isTree(p->right, q->left);
//	}
//
//	return false; 
//}
//
//bool isSymmetric(struct TreeNode* root)
//{
//	if (root == NULL)
//		return true;
//
//	return isTree(root->left, root->right);
//}
//
////------------------------------------------------------------------------------------//
////翻转二叉树
//
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
//
//struct TreeNode* mirrorTree(struct TreeNode* root)
//{
//	if (root == NULL)
//		return NULL;
//
//	struct TreeNode* tmp = root->left;
//	root->left = root->right;
//	root->right = tmp;
//	mirrorTree(root->left);
//	mirrorTree(root->right);
//
//	return root;
//}
//
////------------------------------------------------------------------------------------//
////另一棵树的子树
//
//
//struct TreeNode {
//	int val;
//	struct TreeNode* left;
//	struct TreeNode* right;
//};
// 
//bool _isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//	if (subRoot == NULL && root == NULL)
//		return true;
//
//	if (root == NULL || subRoot == NULL)
//		return false;
//
//	if (root->val == subRoot->val)
//	{
//		if (_isSubtree(root->left, subRoot->left)
//			&& _isSubtree(root->right, subRoot->right))
//			return true;
//	}
//
//	return false;
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//	if (root == NULL)
//		return false;
//
//	if (root->val == subRoot->val)
//	{
//		if (_isSubtree(root->left, subRoot->left)
//			&& _isSubtree(root->right, subRoot->right))
//			return true;
//	}
//
//	return isSubtree(root->left, subRoot)
//		|| isSubtree(root->right, subRoot);
//}
//------------------------------------------------------------------------------------//