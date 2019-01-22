
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
using namespace std;


class String
{
public:
	String(char* s = "")//构造函数
	{
		if (s == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(s) + 1];
		_size = strlen(s);
		_capacity = strlen(s) + 1;
		strcpy(_str, s);
	}

	~String()//析构函数
	{
		if (this)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	String(String& s)//拷贝函数
		:_str( new char[strlen(s._str) + 1])
	{
		swap(_str, s._str);
	}

	String& operator=(String s);//赋值函数
	bool operator == (const String& s);//比较大小
	bool operator != (const String& s);//比较大小
	bool operator <= (const String& s);//比较大小
	bool operator < (const String& s);//比较大小
	//void operator => (const String& s);//比较大小
	bool operator > (const String& s);//比较大小

	void PushBack(char ch);//头插
	void Append(const char* str);//尾插
	void Insert(size_t pos, char ch);//在后面追加字符
	void Insert(size_t pos,  const char* ch);//在后面追加字符串
	void Earse(size_t pos);//删除pos个
	void Find(char a);//查找A所在的位置
	void operator+=(const String& s);
	void CheckCP();
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
	
		cout << s._str;
		return _cout;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;

	const static size_t npos;
};

//void Test1()
//{
//	
//	String s2("hello world");
//	String s1;
//	s1 = s2;
//	cout << s2 << endl;
//	cout << s1;
//}

