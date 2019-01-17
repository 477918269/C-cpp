#include<iostream>
#include<stdlib.h>

using namespace std;


class Date
{
public:


	int Monthday(int year, int month)
	{
		int a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
			{
				return 29;
			}
			return 28;
		}
		return a[month];
	}

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		if (!(this == &d))
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
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
		while ((_day + days) >= Monthday(_year,_month))
		{
			days -= (Monthday(_year, _month) - _day);
			if (_month == 12)
			{
				_year += 1;
				_month = 1;
			}
			_day = 0;
			_month += 1;
			
		}
		_day = _day + days;
		
		return *this;
	}

	Date operator-(int days)
	{
		while ((_day - days) <= 0)
		{
			days -= _day;
			if (_month == 1)
			{
				_year -= 1;
				_month = 12;
			}
			_day = Monthday(_year, _month - 1);
			_month -= 1;
			
		}
		_day = _day - days;
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

		while (min != max)
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
		*this = *this - 1;
		return *this;
	}

	Date operator--(int)
	{
		Date tmp(*this);
		*this + 1;
		return tmp;
	}

	bool operator > (const Date& d)const
	{
		return (_year > d._year)
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day);
	}

	bool operator>=(const Date& d)const
	{
		return !(*this < d);
	}

	bool operator<(const Date& d)const
	{
		return (_year < d._year)
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator <= (const Date& d)const
	{
		return !(*this > d);
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void Test1()
{
	Date d1(2019, 1, 17);
	Date d2(2019, 1, 18);
	
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl; 
	cout << (d1 == d2) << endl;

}

void Test2()
{
	Date d1(2019, 1, 17);
	/*d1 + 15;
	d1.Print();*/
	//d1 - 17;
	//d1++(0).Print();
	//(++d1).Print();//µ÷ÓÃÇ°ÖÃ++
}

void Test3()
{
	Date d1(2019, 1, 17);
	Date d2(2019, 2, 21);
	cout << (d1 - d2) << endl;

}

int main()
{
	Test3();
	system("pause");
	return 0;
}