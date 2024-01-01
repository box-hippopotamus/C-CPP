#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�������Ľڵ�
BTNode* BuyTreeNode(char x);

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

// ����������
void BinaryTreeDestory(BTNode** root);

// �������ڵ����
int BinaryTreeSize(BTNode* root);

//�����ĸ߶� 
int BinaryTreeHeight(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root);
