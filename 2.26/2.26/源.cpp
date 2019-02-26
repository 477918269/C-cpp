#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string.h>
#include<assert.h>

using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
		_str[_size] = '\0';
	}

	String(const String& s)
		:_str(new char[s._capacity + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* Pstr = new char[s._capacity + 1];
			strcpy(Pstr, s._str);
			delete[] _str;
			_str = Pstr;
			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}

	}
	bool operator<(const String& s)
	{
		if (strlen(_str) > strlen(s._str))
			return 0;
		else if (strlen(_str) < strlen(s._str))
			return 1;
		else
		{
			char* cur = _str;
			char* pur = s._str;
			while (*cur)
			{
				if (*cur < *pur)
					return 1;
				cur++;
				pur++;
			}
			return 0;
		}
	}
	bool operator>(const String& s)
	{
		return !(*this == s || *this < s);
	}
	bool operator<=(const String& s)
	{
		return (*this < s) || (*this == s);
	}
	bool operator>=(const String& s)
	{
		return !(*this < s) || (*this == s);

	}
	bool operator==(const String& s)
	{
		if (_size != s._size)
		{
			return 0;
		}
		char* cur = _str;
		char* pur = s._str;
		while (*cur)
		{
			if (*cur != *pur)
				return 0;
			cur++;
			pur++;
		}
		return 1;
	}
	bool operator!=(const String& s)
	{
		return !(*this == s);
	}

	void Reserve(size_t n)
	{
		if (_capacity <= n)
		{

			char* pcur = new char[n + 1];
			strcpy(pcur, _str);
			delete[] _str;
			_str = pcur;
			_capacity = n;
		}

	}
	void PushBack(char ch)
	{
		if (_size == _capacity || _size + 1 == _capacity)
		{
			_capacity == 0 ? 4 : _capacity *= 2;
			Reserve(_capacity);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	// "hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
	void Append(const char* str)
	{
		if (_size + strlen(str) >= _capacity)
		{
			while (_size + strlen(str) >= _capacity)
			{
				_capacity == 0 ? 4 : _capacity *= 2;
			}
			Reserve(_capacity);
		}
		strcpy(_str + _size, str);
		_size += strlen(str);
		_str[_size] = '\0';
	}

	String& operator+=(char ch)
	{
		PushBack(ch);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	void Insert(size_t pos, char ch)
	{
		if (_size + 1 >= _capacity)
		{
			_capacity == 0 ? 4 : _capacity *= 2;
			Reserve(_capacity);
		}
		int cur = pos;
		int endl = _size;
		while (endl != pos)
		{
			_str[endl + 1] = _str[endl];
			endl--;
		}
		_str[pos] = ch;
	}

	void Insert(size_t pos, const char* str)
	{
		if (_size + strlen(str) >= _capacity)
		{
			while (_size + strlen(str) >= _capacity)
			{
				_capacity == 0 ? 4 : _capacity *= 2;
			}
			Reserve(_capacity);
		}
		int cur = pos;
		int endl = _size;
		int pur = strlen(str);
		while (cur + pur != endl)
		{
			_str[endl + pur] = _str[endl];
			endl--;
		}
		while (pos != pos + pur)
		{
			_str[pos++] = *str++;
		}
	}

	void Erase(size_t pos, size_t len)
	{
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';

		}
		else
		{
			int cur = pos;
			int endl = _size;
			while (cur + len != endl)
			{
				_str[cur] = _str[cur + len];
				cur++;
			}
			_size -= len;
			_str[_size] = '\0';
		}
	}
	/*	{
	if (pos + len >= _size)
	{
	_size = pos;
	_str[_size] = '\0';

	}
	else
	{
	for (size_t i = pos + len; i < _size ; i++)
	{
	_str[pos++] = _str[i];
	}
	_str[pos] = '\0';

	}
	*/
	size_t Find(char ch, size_t pos = 0)
	{
		int count = 0;
		while (*_str)
		{
			if (*_str == ch)
				return count;
			_str++;
			count++;
		}
		return 0;
	}

	size_t Find(const char* str, size_t pos = 0)
	{
		char* cur = _str;
		while (*cur)
		{
			char* pur = cur;
			const char* cut = str;
			while (*pur++ == *cut++)
			{
				if (cut == '\0')
					return 1;
			}
			cur++;
		}
		return 0;
	}


	char* c_str()
	{
		return _str;
	}

	char& operator[](size_t pos)
	{
		//assert(pos < _size);

		return _str[pos];
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}
private:
	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& _cout, const String& s)
{
	cout << s._str;
	return _cout;
}


void Test()
{
	String s1;
	String s2("world");
	String s3(s2);

	s1 = s3;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;


}

void Test1()
{
	String s1("abcd");
	String s2("abcd");
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 < s2) << endl;

}

void Test2()
{
	String s1("abcdef");
	/*s1.PushBack('a');
	s1.Append("abc");
	s1.Insert(2, 'g');*/
	s1.Erase(3, 1);
	cout << s1 << endl;

}
int main()
{
	//Test();
	//Test1();
	Test2();
	system("pause");
	return 0;
}