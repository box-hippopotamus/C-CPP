#include "Tree.h"
#include "Queue.h"

//�������Ľڵ�
BTNode* BuyTreeNode(char x)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}

	root->data = x;
	root->left = NULL;
	root->right = NULL;

	return root;
}

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[(*pi)++] == '#')
		return NULL;

	BTNode* root = BuyTreeNode(a[(*pi)++]);

	root->left = BinaryTreeCreate(a, pi);
	root->right = BinaryTreeCreate(a, pi);

	return root;
}


// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);
	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//�����ĸ߶� 
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	return fmax(BinaryTreeHeight(root->left), BinaryTreeHeight(root->right)) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* p = BinaryTreeFind(root->left, x);

	if (p != NULL)
		return p;

	p = BinaryTreeFind(root->right, x);

	return p;
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return 0;

	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return 0;

	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	int TreeLevel = 1;

	while (!QueueEmpty(&q))
	{
		while (TreeLevel != 0)
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);

			printf("%c ", front->data);
			if (front->left)
				QueuePush(&q, front->left);
			if (front->right)
				QueuePush(&q, front->right);
			TreeLevel--;
		}
		TreeLevel = QueueSize(&q);
		printf("\n");
	}

	QueueDestroy(&q);
}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;

			QueuePush(&q, root->left);
			QueuePush(&q, root->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front != NULL)
			return false;
	}

	QueueDestroy(&q);
	return true;
}