#include"game.h"
int main()
{

	char a[100] = "abc##de#g##f###";
	int index = 0;
	BTNode* root = BinaryTreeCreate(a, &index);
	//BinaryTreeInOrder(root);
	//int let = BinaryTreeSize(root);
	//int let = BinaryTreeLeafSize(root);
	//int let = BinaryTreeLevelKSize(root, 3);
	int let = BinaryTreeFind(root, BTDataType a);
	printf("%d", let);
	BinaryTreeDestory(root);
	system("pause");
	
	
	return 0;
}