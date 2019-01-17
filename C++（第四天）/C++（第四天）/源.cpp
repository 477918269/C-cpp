#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date()//无参构造函数
//	{}
//	//Date(int year = 1999, int month = 6, int day = 8)//带参构造函数
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time s;
//};



//int main()
//{
//	Date d1;
//	d1.Print();
//	//Date d2(2019, 1, 17);
//	//d1.Print();
//	//d2.Print();
//	
//	system("pause");
//	return 0;
//}

//class String 
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~String()
//	{ 
//		cout << "~String()" << endl;
//		free(_str);
//	} 
//private:
//	char* _str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int    _age;
//};
//
//int main()
//{
//	Person s;
//	system("pause");
//	return 0;
//}

class Date 
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{ 
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator == (const Date& d2)
	{
		return _year == d2._year
			&&_month == d2._month
			&&_day == d2._day;
	}
	int _year;
	int _month;
	int _day;
};

void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}
