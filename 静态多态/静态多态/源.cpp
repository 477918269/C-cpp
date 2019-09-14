#include<iostream>

using namespace std;
class Base
{
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
};

class Derive : public Base
{
public:
	void fun()
	{
		cout << "Derive::fun()" << endl;
	}
};

void Test1()
{
	Base b;
	Derive d;

	Base* pb = &b;
	Derive* pd = &d;

	pb->fun();
	pd->fun();

	pb = &d;//通过指针，想要调用Derive中的fun()
	pb->fun();

	Base& rb = b;
	Derive& rd = d;

	rb.fun();
	rd.fun();

	Base& rb2 = d;//通过引用，想要调用Derive中的fun()
	rb2.fun();
}

int main()
{
	Test1();
	system("pause");
	return 0;
}