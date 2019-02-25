#include<iostream>

using namespace std;

class Date
{
public:

	int Yearmonth(int year, int month)
	{
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
				return 29;
			return 28;
		}
		return a[month];
	}
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
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
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	Date operator+(int days)
	{
		int day = days + _day;
		while (day >= Yearmonth(_year, _month))
		{
			if (_month == 12)
			{
				_year += 1;
				_month = 1;
				day -= Yearmonth(_year, _month);
			}
			else
			{
				day -= Yearmonth(_year, _month);
				_month += 1;

			}
		}
		_day += days;
		return *this;
	}

	Date operator-(int days)
	{
		while (days >= _day)
		{
			if (_month == 1)
			{
				_year -= 1;
				_month = 12;
				days = days - _day;
				_day = Yearmonth(_year, _month);
			}
			else
			{
				days -= _day;
				_month -= 1;
				_day = Yearmonth(_year, _month);
			}

		}
		_day = Yearmonth(_year, _month) - days;
		return *this;
	}
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		int days = 0;
		if (min >= max)
		{
			Date tmp = max;
			max = min;
			min = tmp;
			flag = -1;
		}

		while (min != max)//ÒÀ´ÎÀÛ¼Ó
		{
			++min;
			++days;
		}
		return days;
	}

	Date& operator++()
	{
		*this + 1;
		return *this;
	}

	Date operator++(int)
	{
		Date tmp(*this);
		*this + 1;
		return tmp;

	}
	Date& operator--()
	{
		*this - 1;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		*this - 1;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	bool operator>=(const Date& d)const
	{
		return (*this > d || *this == d);
	}

	bool operator<(const Date& d)const
	{
		return !(*this > d) && !(*this == d);
	}

	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}

	bool operator==(const Date& d)const
	{
		return (_year == d._year &&
			_month == d._month &&
			_day == d._day);
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test1()
{
	Date s1(1999, 6, 8);
	Date s2(1999, 6, 8);
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 < s2) << endl;

}

void Test2()
{
	Date s1(1999, 6, 8);
	s1 - 30;
	s1.Print();

}