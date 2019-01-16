#include<iostream>
#include<stdlib.h>
using namespace std;

//inline int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	system("pause");
//	return 0;
//}
//int TestAuto()
//{ 
//	return 10;
//}


class Date
{
public:

	int add()
	{
		return this;
	}
public:
	int _year;
	int _month;
	int _day;
};



int main() 
{
	///*int a = 10;
	//auto b = a;
	//auto c = 'a';
	//auto d = TestAuto();
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//cout << typeid(d).name() << endl;
	

	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化*/
	//int a[] = { 1, 2, 3, 4, 5 };
	//for (auto e : a)
	//	e *= 2;
	//for (auto e : a)
	//	cout << e << " "<<endl;

	/*Date d1;
	d1._year = 2019;
	d1._month = 1;
	d1._day = 16;
	d1.Print();*/

	system("pause");
	return 0;
}
//void Print()
//{
//	cout << _year <<endl;
//}