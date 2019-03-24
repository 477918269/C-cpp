#include<iostream>

using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "支付半价票" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void BuyTicket()//不规范写法
//		
//	virtual void BuyTicket()
//	{
//		cout << "支付全价票" << endl;
//	}
//};
//
//class A
//{};
//
//class B : public A
//{};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};



//void Func(Person& people)
//{
//	people.BuyTicket();
//}



//void Test()
//{
//	Person p;
//	Func(p);
//
//	Student s;
//	Func(s);
//}

//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz Good" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "Benz Good" << endl;
//	}
//};

//描述：override保留字表示当前函数重写了基类的虚函数。
//目的：1.在函数比较多的情况下可以提示读者某个函数重写了基类虚函数（表示这个虚函数是从基类继承，不是派生类自己定义的）；2.强制编译器检查某个函数是否重写基类虚函数，如果没有则报错。
//用法：在类的成员函数参数列表后面添加该关键字既可。
//例子：
//class Base ｛
//	virtual void f();
//}；
//class Derived : public Base {
//	void f() override; // 表示派生类重写基类虚函数f
//	void F() override;//错误：函数F没有重写基类任何虚函数
//}；
//注意：override只是C++保留字，不是关键字，这意味着只有在正确的使用位置，oerride才启“关键字”的作用，其他地方可以作为标志符（如：int override；是合法的）。

//final关键字
	//class Car
	//{
	//public:
	//	virtual void Drive() final;
	//};
	//
	//class Benz : public Car
	//{
	//public:
	//	virtual void Drive() override
	//	{
	//		cout << "Benz Good" << endl;
	//	}
	//};

//class Base
//{
//public:
//	virtual void Func()
//	{
//		cout << "Func() " << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Fun2()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//
//class Drive : public Base
//{
//public:
//	virtual void Func()
//	{
//		cout << "Drive :: Func" << endl;
//	}
//	virtual void Ala()
//	{
//	}
//protected:
//	int _d = 2;
//};

class Base
{
public:
	virtual void Func()
	{
		cout << "Base::Func() " << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Fun2()" << endl;
	}

	virtual void Func3()
	{
		cout << "Base::Fun3()" << endl;
	}
private:
	int _b = 1;
};

class Drive : public Base
{
public:
	virtual void Func()
	{
		cout << "Drive :: Func" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	//Person* p1 = new Person;
	//Person* p2 = new Student;

	//delete p1;
	//delete p2;
	//Benz b;
	//b.Drive();
	Base b;
	Drive d;
	/*printf("%d", sizeof(d));*/
	system("pause");
	return 0;
}