//#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//	int m = 0123;
//	int n = 123;
//	printf("%o %o\n", m, n);
//	system("pause");
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int f(int n)
//{  
//	if (n==1)
//		return 1;
//	else
//		return (f(n-1)+n*n*n);
//} 
//int main()
//{
//	int s=f(3);
//	cout<<s<<endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y; 
//} 
//int main()
//{ 
//	int a = '1', b = '1', c = '2';
//	char s = fun(fun(a, b), fun(b, c));
//	cout << s;
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<string.h>
//using namespace std;
//struct One
//{
//	double d;
//	char c;
//	int i;
//};
//struct Two
//{
//	char c;
//	double d;
//	int i;
//};
//
//int main()
//{
//	//cout << sizeof(One) << endl;
//	//cout << sizeof(Two) << endl;
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//
//	system("pause");
//}
//#include<iostream>
//using namespace std;
//void main()
//{
//	int n[][3] = {10,20,30,40,50,60};
//	int (*p)[3]; 
//	p=n;
//	cout<<p[0][0]<<","<<*(p[0]+1)<<","<<(*p)[2]<<endl;
//	system("pause");
//}

#include<iostream>
using namespace std;
class B0//基类BO声明 
{ public:
	//外部接口 
	virtual void display()//虚成员函数
	{
		cout<<"B0::display0"<<endl;
	} 
};
class B1:public B0//公有派生
{
public:
	void display() { cout<<"B1::display0"<<endl; }
}; 
class D1: public B1//公有派生 
{ 
public:
	void display(){ cout<<"D1::display0"<<endl; }
}; 
void fun(B1 ptr)
//普通函数 
{    
	ptr.display();
} 
int main()//主函数 
{
	B0 b0;//声明基类对象和指针
	B1 b1;//声明派生类对象
	D1 d1;//声明派生类对象
	//fun(b0);//调用基类B0函数成员
	fun(b1);
	fun(d1);
	system("pause");
}

