
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "1.h"
#define MAXSIZE 20
int main()
{
	int a[MAXSIZE] = { 0 };
	int i;
	int find;
	int rec;
	BiTree T = NULL;
	BiTree p = NULL;
	srand((unsigned)time(NULL));
	for (i = 1; i<MAXSIZE + 1; i++)
	{
		a[i] = rand() % 50 + 1;
		while (SearchBST(T, a[i], NULL, &p) == 1)
			a[i] = rand() % 10 + 1;
		InsertBST(&T, a[i]);
	}

	printf("先序: ");
	PreorderTraverse(T);
	printf("\n");
	printf("中序: ");
	InorderTraverse(T);
	printf("\n");
	printf("后序: ");
	PostorderTraverse(T);
	printf("\n");

	//print_List(a,MAXSIZE);
	while (1)
	{
		printf("你想查找的数据为：");
		scanf("%d", &find);
		rec = SearchBST(T, find, NULL, &p);
		if (rec == 1)
			printf("找到了!\n");
		else
			printf("没找到\n");
	}
}