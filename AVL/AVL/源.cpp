#include<iostream>

using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	int _bf;
	T _data;

	AVLTreeNode(const T& data)
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_bf(0),
		_data(data)
	{
	}
};

template<class T>
class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;
	AVLTree()
		:_root(nullptr)
	{

	}
	~AVLTree()
	{
		_root = nullptr;
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
		if (parent == _root)
		{
			_root = SUR;
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
		SUR->_bf = parent->_bf = 0;

	}

	void RotatoR(Node* parent)
	{
		Node* SUL = parent->_left;
		Node* SULR = SUL->_right;
		parent->_left = SURL;
		if (SULR != nullptr)
		{
			SULR->_parent = parent;
		}
		Node* grandparent = parent->_parent;
		SUL->_right = parent;
		parent->_parent = SUL;
		if (_root == parent)
		{
			_root = SUL;
		}
		else
		{
			if (grandparent->_left = parent)
			{
				grandparent->_left = SUL;
			}
			else
			{
				grandparent->_right = SUL;
			}
		}
		SUL->_parent = grandparent;
		SUL->_bf = parent->_bf = 0;
	}

	void RotatoRL(Node* parent)
	{
		Node* SUR = parent->_right;
		Node* SURL = SUR->_left;
		int bf = SURL->_bf;

		RotatoR(SUR);
		RotatoL(parent);

		if (bf == 0)
		{
			SUR->_bf = parent->_bf = 0;
		}
		else if (bf = -1)
		{
			SUR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf = 1)
		{
			SUR->_bf = 0;
			parent->_bf = -1;
		}
		SURL->_bf = 0;
	}

	void RotatoLR(Node* parent)
	{
		Node* SUL = parent->_left;
		Node* SULR = SUL->_right;
		int bf = SULR->_bf;

		RotatoL(SUL);
		RotatoR(parent);

		if (bf == 0)
		{
			parent->_bf = SUL->_bf = 0;
		}
		else if (bf == 1)
		{
			SUL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = -1;
			SUL->_bf = 0;
		}
		SULR->_bf = 0;
	}

	bool Insert(T& n)
	{
		if (_root == nullptr)
		{
			_root = new Node(n);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_data < n)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data > n)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(n);
		if (cur->_data < parent->_data)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
				break;
			else if(abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
						RotatoL(parent);
					else if (cur->_bf == -1)
						RotatoRL(parent);
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
						RotatoR(parent);
					else if (cur->_bf == 1)
						RotatoLR(parent);
				}

				break;
			}
			else
				assert(false);

		}
		return true;

	}
private:
	Node* _root;
};



int main()
{
	AVLTree<int> AV;
	return 0;
}