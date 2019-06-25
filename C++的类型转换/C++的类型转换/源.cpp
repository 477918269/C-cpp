#include<iostream>

using namespace std;


class A
{
public:
	virtual void f(){}
};

class B :public A
{};

void fun(A* pa)
{
	B* pb1 = static_cast<B*> (pa);
	B* pb2 = dynamic_cast<B*> (pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;

}

//typedef void(*FUNC)();
//int ALA(int i)
//{
//	cout << "ALA" << endl;
//	return 0;
//}
//
//void Test()
//{
//	FUNC f = reinterpret_cast<FUNC> (ALA);
//	f();
//}

class ALA
{

};
int main()
{
	//Test();
	A a;
	B b;

	fun(&a);
	fun(&b);

	//int i = 1;
	//double d = i;

	////printf("%d, %.2f\n", i, d);
	////隐式类型转换 隐式转换：相关类型，相近类型
	//int* p = &i;
	////显示类型转换 显示转换：无关类型
	//int address = reinterpret_cast<int> (p);
	//int n = 10;
	//size_t pos = 0;
	//while (n >= pos)
	//{
	//	cout << n << endl;
	//	n--;
	//}


	//double d = 13.14;
	//int a = static_cast<int> (d);
	//
	//cout << a << endl;
	
	//const int a = 2;
	//int* p = const_cast<int*> (&a);
	//*p = 3;
	//cout << *p << endl;


	system("pause");
	return 0;
}