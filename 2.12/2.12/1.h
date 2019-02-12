#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int PreorderTraverse(BiTree T);
int InorderTraverse(BiTree T);
int PostorderTraverse(BiTree T);
int InsertBST(BiTree *T, int key);
int SearchBST(BiTree T, int key, BiTree f, BiTree *p);
#endif