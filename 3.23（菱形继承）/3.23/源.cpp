#include<iostream>

using namespace std;

//菱形继承
class Person
{
public:
	string _name;
};

class Student : virtual public Person//借用虚拟继承解决菱形继承的二义性和冗余性
{
protected:
	int _num;
};

class Teacher : virtual public Person
{
protected:
	int _id;
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};
//
//void Test()
//{
//	Assistant a;
//	//无法访问，存在二义性
//	//a._name = "aoliao";
//	//需要指定访问哪个父类的成员可以解决二义性，但是存在数据冗余的问题
//	a.Student::_name = "aoliao";
//	a.Teacher::_name = "maliao";
//
//
//}

//class A
//{
//public:
//	int _a;
//};
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
////class D : public B, public C
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//void Test()
//{
//	Assistant a;
//	a._name = "aoliao";
//}
//
//void Test1()
//{
//	D d;
//	d.B :: _a = 1;
//	d.C :: _a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//}

class Base1
{
public:
	int _a;
};

class Base2
{
public:
	int _b;
};

class Derive : public Base1, public Base2
{
public:
	int _c;
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