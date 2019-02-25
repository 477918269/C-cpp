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
			return ;
		}
		_str = new char[strlen(str + 1)];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str + 1)])
	{
		strcpy(s._str, _str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* Pstr = new char[strlen(s._str + 1)];
			strcpy(Pstr, s._str);
			delete[] _str;
			_str = Pstr;
		}

		return *this;
	}

	~String()
	{
		assert(_str);
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};


void Test()
{
	String s1("abcd");
	String s2(s1);
}
