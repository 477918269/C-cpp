#include<iostream>

using namespace std;
//#include<stdio.h>
//int Add(int a, int b)
//{
//	return a;
//}
//
//int Add(double a, double b)
//{
//	return b;
//}
//
//void TestFunc(int a = 10) 
//{ 
//	cout << "void TestFunc(int)" << endl;
//}
//
//void TestFunc(int a) 
//{
//	cout << "void TestFunc(int)" << endl;
//}

//void TestFunc(int a);
//void TestFunc(double a);
//int main()
//{
//	///*Add(10, 20);
//	//Add(10.0, 20.0);*/
//	//TestFunc(1);
//	//TestFunc(1.0);
//	/*int a = 10;
//	int& ra = a;
//	printf("%p\n", &a);
//	printf("%p\n", &ra);*/
//	const int a = 10;
//	//int &ra = 0;//该语句编译出错，a为常数，本身应该为定值。
//	const int& ra = a;
//	double b = 0;
//	const int &rb = b;
//	int &c = 10;//不能直接转换。
//
//	
//	system("pause");
//	return 0;
//}

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int& ret = Add(1, 2);

	cout << "Add(1, 2) is :" << ret << endl;
	system("pause");
	return 0;
}
