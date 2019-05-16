#include<iostream>

using namespace std;

class Person
{
private:
	virtual void id()
	{
		cout << "id()" << endl;
	}

	void name()
	{
		cout << "name" << endl;
	}
public:
	void all()
	{
		id();
		name();
	}
	void fun1(string a)
	{
		cout << "Person(fun1 string)" << endl;
	}
	void fun1(int a)//两个fun1在Person的函数范围内被重载了
	{
		cout << "Person(fun1 int)" << endl;
	}

};

class student :public Person
{
public:
	void id()//基类中的id为虚函数，此处为重写
	{
		cout << " student id()" << endl;
	}

	void fun1(int a, int b)//fun1不为虚函数，此处为重定义
	{
		cout << "student fun1(int a, int b)" << endl;
	}

	void name()
	{
		cout << "student name()" << endl;
	}

};

int main()
{
	student s;
	Person *p = &s;
	p->all ();
	s.all();
	s.name();
	system("pause");


}


