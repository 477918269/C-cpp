#include<iostream>

using namespace std;

class Base1
{
public:
	int _b1;
};

class Base2
{
public:
	int _b2;
};

class Derive : public Base1, public Base2
{
public:
	int _b;

};

int main()
{
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

	system("pause");
	return 0;
}