#include"1"


int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		printf("Пе\n");
		return 0;
	}
	else if (key == T->data)
	{
		*p = T;
		printf("==\n");
		return 1;
	}
	else if (key < T->data)
	{
		printf("<\n");
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		printf(">\n");
		return SearchBST(T->rchild, key, T, p);
	}
}

int InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;
		if (!p)
			*T = s;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return 1;
	}
	else
		return 0;
}

int PostorderTraverse(BiTree T){
	if (T == NULL) return 1;
	else{
		PostorderTraverse(T->lchild);
		PostorderTraverse(T->rchild);
		printf("%d ", T->data);

	}
}