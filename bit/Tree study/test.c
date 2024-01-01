
#include "Queue.h"


//------------------------------------------------------------------------------------------//
//α��һ����
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
//ǰ�����
void PrevOrder(TreeNode* root)
{
	if (root == NULL)//Ϊ��ֱ�ӷ���
	{
		return;
	}

	printf("%d ", root->data);//������
	PrevOrder(root->left);//����������
	PrevOrder(root->right);//����������
}

//�������
void InOrder(TreeNode* root)
{
	if (root == NULL)//Ϊ��ֱ�ӷ���
	{
		return;
	}

	InOrder(root->left);//����������
	printf("%d ", root->data);//������
	PrevOrder(root->right);//����������
}

//�������
void PostOrder(TreeNode* root)
{
	if (root == NULL)//Ϊ��ֱ�ӷ���
	{
		return;
	}

	PostOrder(root->left);//����������
	PostOrder(root->right);//����������
	printf("%d ", root->data);//������
}

//�������
void LevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	int LevelSize = 1;
	//һ��һ�������
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

//�����Ľڵ���Ŀ
int TreeSize(TreeNode* root)
{
	//if (root == NULL)//Ϊ��ֱ�ӷ���
	//{
	//	return 0;
	//}

	//int count = 1 + TreeSize(root->right) + TreeSize(root->left);

	//return count;
	//-----------------------------------------------//
	//�Ż���

	return root == NULL ? 0 : 1 + TreeSize(root->right) + TreeSize(root->left);
}

//������Ҷ�ӽڵ���Ŀ
int TreeLeafSize(TreeNode* root)
{
	if (root == NULL)//Ϊ��ֱ�ӷ���
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
	//�Ż��� 

	if (root == NULL)//Ϊ��ֱ�ӷ���
	{
		return 0;
	}

	int count = TreeLeafSize(root->left) + TreeLeafSize(root->right);
	return count == 0 ? count + 1 : count;

	//-----------------------------------------------//
	//����汾��
	// 
	//Ϊ��ֱ�ӷ���
	if (root == NULL)
		return 0;

	//���Ҷ�Ϊ�գ�˵��ΪҶ�ӣ���¼��Ҷ�ӣ�����1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//�Ȳ��ǿ�,Ҳ����Ҷ�ӣ�����Ŀǰ�ڵ��¼������Ҷ����Ŀ
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}


//�����ĸ߶� 
int TreeHeight(TreeNode* root)
{
	if (root == NULL)//Ϊ��ֱ�ӷ���
	{
		return 0;
	}

	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
}

//���k��ڵ����
int TreeLevlk(TreeNode* root,int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;
	else
		return TreeLevlk(root->left, k - 1) + TreeLevlk(root->right, k - 1);
}

//����ֵΪx�Ľڵ�
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

//ͨ��ǰ����������鹹��������
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

//�ж�һ�����ǲ�����ȫ������
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

	//ǰ�������պ������滹�зǿգ��Ͳ�����ȫ������
	while (!QueueEmpty(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)//�ǿ�
			return false;
	}
	QueueDestroy(&q);

	return true;
}

//������
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
////��ֵ������
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
////��ͬ����
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
////ǰ�����
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
////�Գƶ�����
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
////��ת������
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
////��һ����������
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