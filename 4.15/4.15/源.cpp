#include<iostream>

using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& date = T())
	: _left(nullptr)
	, _right(nullptr)
	, _date(date)
	{}

	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _date;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	~BSTree()
	{
		Destroy(_root);
	}
	bool insert(const T& date)
	{
		if (_root == nullptr)
		{
			_root = new Node(date);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			parent = cur;
			if (date > cur->_date)
				cur = cur->_left;
			else if (date < cur->_date)
				cur = cur->_right;
			else
				return false;
		}

			
		if (parent->_left == cur)
		{
			cur = new Node(date);
			parent->_left = cur;

		}
		else
		{
			cur = new Node(date);
			parent->_right = cur;

		}
		return true;
	}

	void Inorder()
	{
		_Inorder(_root);
	}

	Node* Find(const T& date)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_date == date)
				return cur;
			else if (date > cur->_date)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return nullptr;
	}

	bool Erase(T& date)
	{
		if (_root == nullptr)
			return false;

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (date == cur->_date)
				break;
			else if (date > cur->date)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		if (cur == nullptr)
			return false;
		if (cur->_left == nullptr)
		{
			Node* pur = cur->_right;
			if (parent->_left == cur)
			{
				delete cur;
				parent->_left = pur;
			}
			else
			{
				delete cur;
				parent->_right = pur;
			}			
		}

		else if (cur->_right == nullptr)
		{
			Node* pur = cur->_left;
			if (parent->_left == cur)
			{
				delete cur;
				parent->_left = pur;
			}
			else
			{
				delete cur;
				parent->_right = pur;
			}
		}
		else
		{

		}
	}
private:
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_date << " ";
		_Inorder(root->_right);
	}
	
	void Destroy(Node* root)
	{
		if (_root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		root = nullptr;
	}
private:
	Node* _root;
};

int main()
{
	BSTree<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.insert(7);
	s.insert(8);
	s.insert(9);
	s.Find(10);
	s.Inorder();
	s.~BSTree();
	system("pause");
}