#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << " - " <<  _month << " - "<<  _day  << endl;
//	}
//
//	void SetDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date a;
//	a.SetDate(2019, 1, 15);
//	a.Print();
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
//		   ~String()
//		   {
//			    cout << "~String()" << endl;
//				free(_str);
//		   } 
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
//	Person p;
//	return 0;
//}


class Date
{
public:

	int YearDay(int year)
	{
		int a[2] = { 365, 366 };
		if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
		{
			return a[1];
		}
		else
			return a[0];
	}

	int _YearDay(int year)
	{
		;
	}

	int MonthDays(int month)
	{
		int x = 0;
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		x = a[month];
		return x;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;

		}
		return *this; //在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this
	}
	Date operator+(int days)
	{
		if (this->_month != 12)
		{

			if (this->_day + days <= MonthDays(this->_month))
			{
				this->_day += days;
			}
			else
			{
				this->_day = this->_day + days - MonthDays(this->_month);//只算days较小的情况
				this->_month += 1;
			}
		}
		else
		{
			this->_day = this->_day + days - MonthDays(this->_month);
			this->_year += 1;
			this->_month = 1;
		}
		return *this;
	}
	Date operator-(int days)
	{
		if (this->_month != 1)
		{
			if (this->_day - days > 0)
			{
				this->_day -= days;
			}
			else
			{
				this->_month -= 1;

				this->_day = MonthDays(this->_month) - (days - this->_day);
			}
		}
		else
		{
			this->_day = MonthDays(this->_month) - (days - this->_day);
			this->_month = 12;
			this->_year -= 1;
		}
		return *this;
	}

	int operator-(const Date& d)
	{

		if (abs(this->_year - d._year) == 0
			&& this->_month - d._month == 0)//同年同月
		{

			int day = this->_day - d._day;
			return day;
		}
		if (this->_year - d._year == 0
			&& this->_month - d._month != 0)//同年不同月
		{
			int day1 = 0;
			int day2 = 0;
			for (int i = this->_month - 1; i > 0; i--)
			{
				day1 = day1 + MonthDays(i);
			}
			for (int i = d._month - 1; i > 0; i--)
			{
				day2 = day2 + MonthDays(i);
			}
			return (day1 + this->_day) - (day2 + d._day);//(这个月之前过的天数+这个月已经过的天数)-(另一个月之前过的天数+另一个月已经过的天数)
		}
		if (abs(this->_year - d._year) == 1)//不同年，年份差一年以内
		{
			int day1 = 0;
			int day2 = 0;
			for (int i = this->_month - 1; i > 0; i--)
			{
				day1 = day1 + MonthDays(i);
			}
			day1 += this->_day;//this->year已经过去的的天数
			day1 = YearDay(this->_year) - day1;//this->year还剩下的天数
			for (int i = d._month - 1; i > 0; i--)
			{
				day2 = day2 + MonthDays(i);
			}
			day1 += d._day;//this->year已经过去的的天数

			return day2 + day1;//返回第一年年剩下的天数加上第二年已经过的天数
			
		}
		if (abs(this->_year - d._year) > 1)//不同年，年份差在一年以上
		{
			int day1 = 0;
			int day2 = 0;
			int day3 = 0;
			int n = 0;
			for (int i = this->_month - 1; i > 0;i--)
			{
				day1 = day1 + MonthDays(i);
			}
			day1 = day1 + this->_day;
			day1 = YearDay(this->_year) - day1;

			for (int i = d._month - 1; i > 0; i--)
			{
				day2 = day2 + MonthDays(i);
			}

			day2 += d._day;

			n = abs(this->_year - d._year) - 1;

			for (int i = 1; i <= n; i++)//算这
			{
				day3 = day3 + YearDay(this->_year + i);
			}
			return day3 + day1 + day2;

		}


		return 0;
	}
	Date& operator++()
	{
		if (this->_year != YearDay(this->_year))
		{
			if (this->_month != MonthDays(this->_month))
			{
				this->_day += 1;
			}
			else
			{
				this->_month += 1;
				this->_day = 1;
			}
		}
		else
		{
			this->_month = 1;
			this->_day = 1;
		}
		return  *this;
	}
	Date operator++(int)
	{

	}
	Date& operator--()
	{
		if (this->_month != 1)//不在一月份
		{
			if (this->_day  != 1)//且不在一号
			{
				this->_day -= 1;
			}
			else//在某月的一号
			{
				this->_month -= 1;
				this->_day = MonthDays(this->_month );
			}
		}
		else
		{
			if (this->_day != 1)//在一月，但不在一号
			{
				this->_day -= 1;
			}
			else//在一月一号
			{
				this->_year -= 1;
				this->_month = 12;
				this->_day = 31;
			}
		}
		return  *this;
	}
	Date operator--(int)
	{

	}
	bool operator>(const Date& d)const
	{
		return _year > d._year
			&& _month > d._month
			&& _day > d._day;
	}
	bool operator>=(const Date& d)const
	{
		return _year >= d._year
			&& _month >= d._month
			&& _day >= d._day;
	}
	bool operator<(const Date& d)const
	{
		return _year < d._year
			&& _month < d._month
			&& _day < d._day;
	}
	bool operator<=(const Date& d)const
	{
		return _year <= d._year
			&& _month <= d._month
			&& _day <= d._day;
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return _year != d._year
			&& _month != d._month
			&& _day != d._day;
	}
	void Print()
	{
		cout << _year << " - " << _month << " - " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(1997, 1, 31);
	Date d2(1999, 2, 1);
	//d1.operator++();
	//d1.operator--();
	//d1.operator--();
	int ret = d1.operator-(d2);
	//d1.Print();


	//Date d2(1999, 8, 8);
	//d1.operator-(3);
	//cout << (d1-(d2))<<endl;
	//d1.operator=(d2);
	//int ret = d1.operator-(d2);
	cout << ret << endl;
	//d1.Print();
	//d2.Print();
	/*cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 > d2) << endl;*/
	system("pause");
	return 0;
}