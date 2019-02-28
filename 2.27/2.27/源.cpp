#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<assert.h>
#include<algorithm>

//#include<vector>
using namespace std;
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "" << *it;
//	}
//	system("pause");
//	return 0;
//}
template<class T>
class Vector
{
public:
	T* begin()
	{
		return _start;
	}

	T* end()
	{
		return _finish;
	}

	const T*Cbegin()
	{
		return _start;
	}

	const T* Cend()
	{
		return _finish;
	}

	size_t Size()
	{
		return _finish - _start;
	}

	size_t Capacity()
	{
		return _endOfstorage - _start;
	}

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfstorage(nullptr)
	{}

	void Reserve(size_t n)
	{
		if ()
		{

		}
	}
private:
	T* _start;
	T* _finish;
	T* _endOfstorage;

};


int main()
{
	
}