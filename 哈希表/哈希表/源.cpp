#include<iostream>
#include<vector>
using namespace std;


////±ÕÉ¢ÁÐ
enum State
{
	EMPTY,
	DELETE,
	EXITS
};


template<class K, class V>
struct HashNode
{

	pair<K, V> _kv;
	State _state;
};
template<class K, class V>
class HashTable
{
	typedef HashNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		CheckCapacity();

		size_t index = _kv.first % _table.size();
		while (_table[index]._state == EXITS)
		{
			if (_table[index]._kv.first == kv.first)
				return false;

			++index;
			if (index == _table.size())
			{
				index = 0;
			}
		}
		_table[index]._kv = kv;
		_table[index]._state = EXITS;
		++_size;
		return true;
	}

	void CheckCapacity()
	{
		if (_table.size() == 0 || (_size * 10) / table.size() == 7)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			HashTable<K, V>newt(newsize);
			for (int i = 0; i < _table.size(); i++)
			{
				newt.Insert(_table[i]);
			}
			_table.swap(newt, _table);

		}
	}

	HashNode* Find(const K& key)
	{
		size_t index = key % _table.size();
		while (_table[index]._state == EXITS)
		{
			if (_table[index]._kv.first == key && _table[index]._state != EXITS)
			{
				return &_table[index];
			}
			++index;
			if (index = _table.size)
			{
				index == 0;
			}
		}
		_table[index].
		return nullptr;
	}

	bool Erase(cosnt K& key)
	{
		HashNode* node = Find(key);
		if (node == nullptr)
		{
			return false;
		}
		else
		{
			node->_state = DELETE;
			--_size;
		}
		
	}
private:
	vector<Node*> _table;
	size_t _size;
};



//¿ªÉ¢ÁÐ

template<class V>
struct HashNode
{
	V _value;
	HashNode<V>* _next;
	HashNode(const V& v)
		:_value(v),
		_next(nullptr)
	{}
};

template<class K, class V, class KeyOfValue, class HashFunc>
class HashTree
{
	stpedef HashNode<V> Node;
public:
	size_t GetIndex(const K& key, size_t size)
	{
		HashFunc hf;
		return hf(key) % size;
	}

	void CheckCapacity()
	{
		if (_size == _table.size())
		{
			size_t newsize = _size == 0 ? 10 : _size * 2;
			vector<Node*> newtable;
			newtable.resize(newsize);

			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					int index = GetIndex(KeyOfValue()(cur->_value), newtable.size());
					cur->_next = newtable[index];
					newtable[index] = cur[i];
					cur = next;
				}
				_table[i] = nullptr;
			}
			_table.swap(newtable);

		}
	}


	pairt<iterator, bool>Insert(const V& v)
	{
		CheckCapacity();

		size_t index = GetIndex(KeyOfValue()(v), _table.size());
		Node* cur = _table[index];
		while (cur)
		{
			if (cur->_value == v)
			{
				return make_pair(iterator(cur, this), false);
			}
			cur = cur->_next;
		}

		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_size;

		return make_pair(iterator(newnode, this), true);
	}

private:
	vector<Node*> _table;
	size_t _size;
};


int main()
{
	//HashTable<int, int> hs;
	system("pause");
	return 0;
}