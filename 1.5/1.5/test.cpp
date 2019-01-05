/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//二叉树的深度
int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	int lefth = 0;
	int righth = 0;
	lefth = maxDepth(root->left) + 1;
	righth = maxDepth(root->right) + 1;


	return lefth >= righth ? lefth : righth;

}

//相同的树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL && q != NULL)
		return false;
	if (p != NULL && q == NULL)
		return false;
	if (p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right)
		)
		return true;
	else
		return false;

	return false;
}

//判断平衡二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int lefth = 1 + TreeSize(root->left);
	int righth = 1 + TreeSize(root->right);
	return lefth > righth ? lefth : righth;
}

bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	int lefth = TreeSize(root->left);
	int righth = TreeSize(root->right);
	if (abs(lefth - righth) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return true;

	return false;
}

//判断平衡二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int swapSize(struct TreeNode* q, struct TreeNode* p)
{
	if (q == NULL && p == NULL)
		return 1;
	if (q != NULL && p == NULL)
		return 0;
	if (q == NULL && p != NULL)
		return 0;
	if (q->val == p->val &&
		swapSize(q->left, p->right) &&
		swapSize(q->right, p->left) &&
		q&& p)
		return 1;
	return 0;
}
bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
		return 1;
	int ret = swapSize(root->left, root->right);
	return ret;
}

//判断一棵树是否为另一棵树的子树。
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int sameTree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;
	if (s != NULL && t == NULL)
		return false;
	if (s == NULL && t != NULL)
		return false;
	if (s->val == t->val &&
		sameTree(s->right, t->right) &&
		sameTree(s->left, t->left))
		return true;
	return false;
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
		return true;
	if (s != NULL && t == NULL)
		return false;
	if (s == NULL && t != NULL)
		return false;
	if (s->val == t->val &&
		sameTree(s, t))
		return true;
	else
	{

		if (isSubtree(s->left, t))
			return true;
		if (isSubtree(s->right, t))
			return true;

	}
	return false;
}