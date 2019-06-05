//#include<iostream>
//
//using namespace std;
//
//void InputParam(int& year, int& Month, int& Day)
//{
//	cin >> year >> Month >> Day;
//}
//
//int Getmonth(int month, int year)
//{
//	int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2)
//	{
//		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
//			return 29;
//		else
//			return 28;
//	}
//	return a[month];
//}
//
//int iConverDate(int year, int Month, int Day)
//{
//	if (year < 0)
//		return -1;
//	if (Month > 12 || Month < 1)
//		return -1;
//	int num = 0;
//	for (int i = 1; i < Month; i++)
//	{
//		num += Getmonth(i, year);
//	}
//	if (Day <= Getmonth(Month, year) && Day > 0)
//		return num + Day;
//	else
//		return -1;
//}
//
//int main()
//{
//	int year = 0;
//	int Month = 0;
//	int Day = 0;
//	InputParam(year, Month, Day);
//	int ret = iConverDate(year, Month, Day);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//const int days[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//int main() {
//	int y, m, d;
//	while (cin >> y >> m >> d) {
//		int ans = days[m - 1] + d;
//		if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && m > 2)
//			ans++;
//		cout << ans << endl;
//	}
//	return 0;
//}

#include<iostream>

using namespace std;

class A
{
public:
	void func()
	{
		cout << "1" << endl;
	}
};

class B :public A
{
public:
	virtual void func()
	{
		cout << "2" << endl;
	}
};

int main()
{
	A* a = new B;
	a->func();
	delete a;
	return 0;
}