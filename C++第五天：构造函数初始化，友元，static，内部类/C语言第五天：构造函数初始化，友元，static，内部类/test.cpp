#include<iostream>
#include<stdlib.h>

using namespace std;


//class Date
//{
//public:
	//Date(int year, int month, int day)
	//	:_year(year)
	//	, _month(month)
	//	, _day(day)
	//{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////初始化只能初始一次，赋值能赋多次
//int main()
//{
//	Date d;
//	return 0;
//}



//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//
//int A::_scount = 0;
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}
//
//int main()
//{
//	TestA();
//	system("pause");
//	return 0;
//}

//class Date;
//class Time
//{
//	friend class Date;//声明日期为时间类的友元类，在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour, int minute, int second)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//class Date {
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _t(0,0,0)
//		{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{       
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;   
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//}; 




class A 
{
private:
	static int k;
	int h;
public:
	class B
	{

	public:
		void foo(const A& a)
		{
				   cout << k << endl;//OK
				   cout << a.h << endl;//OK
		}
	};
};

	int A::k = 1;

int main()
{
	A::B b;
	b.foo(A());
	return 0;
}