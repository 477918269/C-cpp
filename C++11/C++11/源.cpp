#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<initializer_list>
using namespace std;

//class Date
//{
//public:
//
//	Date(int year, int month, int day)
//	:_year(year),
//	_month(month),
//	_day(day)
//	{
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//template<class T>
//class Vector
//{
//
//}

//int main()
//{
//	//int a[] = { 1, 2, 3, 4 };
//	//vector<int> v{1,2,3,4};
//	//Date d = { 1999, 6, 8 };
//	//for (auto e : v)
//	//{
//	//	cout << e << endl;
//	//}
//
//	//for (auto e : a)
//	//{
//	//	cout << e << endl;
//	//}
//	//变量
//	//int x1 = { 10 };
//	//int x2{ 10 };
//	//int x3 = 1 + 2;
//	//int x4{ 1 + 2 };
//	//int x5 = { 1 + 2 };
//	////数组
//	//int a1[5] = { 1, 2, 3, 4, 5 };
//	//int a2[] = { 1, 2, 3, 4, 5 };
//
//	//int* a3 = new int[5] {1, 2, 3, 4, 5};
//
//	////STL容器
//	//vector<int> v{ 1, 2, 3, 4 };
//	//map<string, int> m{ { "苹果", 5 }, { "桃子", 10 } };
//
//	system("pause");
//	return 0;
//
//}

//void* ALA(int size)
//{
//	return malloc(size);
//}

//int main()
//{
//	//没有带参数，推演函数的类型
//	//cout << typeid(decltype(ALA)).name() << endl;
//	////带了参数，推导的是函数返回值的类型，注意：此处只是推演，不执行函数
//	//cout << typeid(decltype(ALA(0))).name() << endl;
//	//map<string, int> m{ { "苹果", 5 }, { "桃子", 10 } };
//	//map<string, int> ::iterator it = m.begin();
//	//auto it = m.begin();
//
//
//	//short a = 32670;
//	//short b = 32670;
//
//	//decltype(a + b) c;
//	//cout << typeid(c).name() << endl;
//	
//
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//		:_year(0),
//		_month(0),
//		_day(0)
//	{}
//
//	Date(int year)
//		:Date()
//	{
//		_year = year;
//	}
//
//	Date(int month)
//		:Date()
//	{
//		_month = month;
//	}
//private:
//	int _year = 1999;
//	int _month = 6;
//	int _day = 8;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//	//显示缺省函数，由编译器生成
//	A() = delete;
//	//在类中声明，在类外定义时让编译器生成默认赋值运算符重载
//	A& operator= (const A& a) = delete;
//private:
//	int _a;
//};
//
////A& A::operator=(const A& a) = delete;
//
//
//int main()
//{
//	A a1(10);
//	//失败，因为没有隐式的构造函数
//	//A a2;
//	//失败，因为没有赋值运算符重载
//	//a2 = a1;
//	return 0;
//
//}


int main()
{
	int a = 10;
	int &lr = a;
	const int&& rr = 10;
	return 0;
}	