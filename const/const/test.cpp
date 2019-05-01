#include<iostream>
#include"test1.cpp"
extern const int k;//在全局作用域声明的const变量是定义该对象的文件的全局变量

using namespace std;

//class A
//{
//public:
//	//类中的const类型需要通过初始化来赋值
//	A(int i)
//		:a(i)
//	{}
//	void Print();
//private:
//	const int a;
//};





//int& reval2 = ival;
int main()
{
	//const int i = 1000;
	//i = 100;
	//const int j, k = 100;
	//A a(1);
	//const int ival = 2019;
	//const int& reval = ival;
	//reval = 100
	//int i = 42; 
	//const int& r = 42;
	//const int& r1 = r + i;
	//cout << r1 << endl;

	//double i = 3.14;
	//const int& j = i;
	////实际转换成
	//int la = i;
	//int k = i;//进行隐式类型转换
	//const int& j = k;

	//const int* a = new const int[100]();
	//const string* s = new string[100];

	//const double* cur;
	//const double pur = 1.2;
	//cur = &pur;
	
	int pur = 10;
	int* const cur = &pur;
	system("pause");

	return 0;
}