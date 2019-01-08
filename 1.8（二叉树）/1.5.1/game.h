#include<stdio.h>
#include<stdlib.h>

typedef char  BTDataType;

typedef struct  BinaryTreeNode
{
	BTDataType _date;
	struct BinaryTreeNode* right;
	struct BinaryTreeNode* left;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
int BinaryTreeFind(BTNode* root, BTDataType x);
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);

void BinaryTreePostOrder(BTNode* root);