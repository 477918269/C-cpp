#include"game.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pindex)
{
	if (a[*pindex] == '#')
	{
		(*pindex)++;
		return 0;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_date = a[*pindex];
		root->left = NULL;
		root->right = NULL;
		(*pindex)++;
		root->left = BinaryTreeCreate(a, pindex);
		root->right = BinaryTreeCreate(a, pindex);
		return root;
	}
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c", root->_date);

		BinaryTreeInOrder(root->left);

		BinaryTreeInOrder(root->right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root != NULL)
	{
		
		BinaryTreeInOrder(root->left);
		
		printf("%c", root->_date );
		
		BinaryTreeInOrder(root->right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root != NULL)
	{

		BinaryTreeInOrder(root->left);

		

		BinaryTreeInOrder(root->right);


		printf("%c", root->_date);
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->left == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

int BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return 0;
	if (root->_date == x)
		return 1;
	int left = BinaryTreeFind(root->left, x);
	int right = BinaryTreeFind(root->right, x);
	if (left == 1)
		return 1;
	if (right == 1)
		return 1;
	
	return 0;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root != NULL)
	{
		BinaryTreeDestory(root->left);
		BinaryTreeDestory(root->right);
		free(root);
	}
}
