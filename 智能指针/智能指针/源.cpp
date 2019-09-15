#include<iostream>
#include<memory>
using namespace std;

//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date()" << endl;
//	}
//	~Date()
//	{
//		cout << "~Date" << endl;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date a;
//	auto_ptr<Date> ap(a);
//	auto_ptr<Date> ad(ap);
//	ad->_day = 0;
//	system("pause");
//	return 0;
//}


class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
	~Date()
	{
		cout << "~Date" << endl;
	}
	int _year;
	int _month;
	int _day;
};
//
//int main()
//{
//	auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);
//	copy->_year = 2019;
//	system("pause");
//}
//template<class T>
//class Autoptr
//{
//public:
//	Autoptr(T* ptr = nullptr)
//		:_ptr(ptr)
// 	{
//	}
//
//	~Autoptr()
//	{
//		if (this)
//		{
//			delete _ptr;
//			_ptr = nullptr;
//		}
//	}
//
//	Autoptr(Autoptr<T>& ptr)
//		:_ptr(ptr._ptr)
//	{
//		ptr._ptr = nullptr;
//	}
//
//	Autoptr<T>& operator=(Autoptr<T>& ptr)
//	{
//		if (this != &ptr)
//		{
//			if (ptr)
//			{
//				delete ptr;
//			}
//			_ptr = ptr._ptr;
//			ptr._ptr = nullptr;
//		}
//		return *this;
//	}
//
//	T* operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	Autoptr<Date> ap(new Date);
//	Autoptr<Date> copy(ap);
//	ap->_year = 2019;
//	system("pause");
//}


template<class T>
class Uniqueptr
{
public:
	Uniqueptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~Uniqueptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}

	T& operator*()
	{
		return _ptr;
	}

	T* operator->()
	{
		return *_ptr;
	}

private:
	Uniqueptr(Uniqueptr<T> const&);
	Uniqueptr& operator=(Uniqueptr<T> const &);

	Uniqueptr(Uniqueptr<T> const&) = delete;
	Uniqueptr& operator=(Uniqueptr<T> cosnt &) = delete;
private:
	T* _ptr;
};

template<class T>
class Sharedptr
{
public:
	Sharedptr(T* _ptr = nullptr)
		:_ptr(ptr),
		_Rcount(new int(1))
	{}

	~Sharedptr()
	{
		if (--(*_Rcount) == 0)
		{
			delete _ptr;
			delete _Rcount;
		}
	}

	Sharedptr(Sharedptr<T>& ptr)
		:_ptr(ptr._ptr),
		_Rcount(ptr._Rcount)
	{
		++(*_Rcount);
	}

	Sharedptr<T> operator=(Sharedptr<T>& ptr)
	{
		if (this != &ptr)
		{

			if (--(*Rcount) == 0)
			{
				delete _ptr;
				delete _Rcount;
			}

			_ptr = ptr._ptr;
			_Rcount = ptr._Rcount;
			++(*Rcount);
		}
	}
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
	int* _Rcount;
};

