#include<iostream>

using namespace std;

enum colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _parent;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	pair<K, V> _kv;
	colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_kv(kv),
		_col(RED)
	{
	}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	~RBTree()
	{
		_root = nullptr;
	}

	bool Insert(const pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_right
			}
			else
				return false;
		}

		cur = new Node(kv);
		cur->_col = RED;

		if (kv.first < cur->_kv.first)
		{
			cur->_left = pur;
		}
		else
		{
			cur->_right = pur;
		}

		while (parent && parent->_col == RED)
		{
			Node* grandparent = parent->_parent;
			if (parent == grandparent->_left)
			{
				Node* uncle = grandparent->_right;
				if (uncle->_col == RED && uncle)
				{
					uncle->_col = parent->_col = BLACK;
					grandparent->_col = RED;

					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_right == cur)
					{
						RotatoL(parent);
						swap(parent, cur);
					}
					RotatoR(grandparent);
					parent->_col = BLACK;
					grandparent->_col = RED;
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				if (uncle->_col == RED && uncle)
				{
					parent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					parent = grandparent;
					grandparent = parent->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotatoR(parent);
						swap(parent, cur);
					}
					RotatoL(grandparent);
					parent->_col = BLACK;
					grandparent->_col = RED;
					break
				}
			}

		}
		_root->_col = BLACK;
		return true;
	}

	bool ISRBtree()
	{
		if (_root == RED)
			return false;

		size_t n = 0;
		size_t m = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				n++;
			cur = cur->_left;
		}
		return _ISRBtree(_root, m, n);
	}

	bool _ISRBtree(Node* root, size_t m, size_t n)
	{
		if (root == NULL)
		{
			if (m == n)
				return true;
			else
				return false;
		}

		if (root->_col == BLACK)
		{
			m++;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			return false;
		}

		return _ISRBtree(root->_left, m, n) && _ISRBtree(root->_right, m, n);
	}

	void RotatoL(Node* parent)
	{
		Node* SUR = parent->_right;
		Node* SURL = SUR->_left;
		parent->_right = SURL;
		if (SURL != nullptr)
		{
			SURL->_parent = parent;
		}
		Node* grandparent = parent->_parent;
		SUR->_left = parent;
		parent->_parent = SUR;
		if (_root == parent)
		{
			SUR = _root;
		}
		else
		{
			if (grandparent->_left = parent)
			{
				grandparent->_left = SUR;

			}
			else
			{
				grandparent->_right = SUR;

			}
		}
		SUR->_parent = grandparent;
	}

	void RotatoR(Node* parent)
	{
		Node* SUL = parent->_left;
		Node* SULR = SUL->_right;
		parent->_left = SULR;
		if (SULR != nullptr)
		{
			SULR->_parent = parent;
		}

		Node* grandparent = parent->_parent;
		SUL->_right = parent;
		parent->_parent = SUL;

		if (_root == parent)
		{
			SUL = _root;
		}
		else
		{
			if (grandparent->_left = _parent)
			{
				grandparent->_left = SUL
			}
			else
			{
				grandparent->_right = SUL;
			}
		}
		SUL->_parent = grandparent;
	}
private:
	Node* _root;

};


int main()
{

	system("pause");
	return 0;
}