#include<iostream>

using namespace std;

//int Func1(int n)
//{
//	int count = 0;
//	for (int i = 1; i <= n / 2; i++)
//	{
//		if (n % i == 0)
//			count += i;
//	}
//	return count;
//}
//
//int count(int n)
//{
//	int num = 0;
//	for (int i = 2; i < n; i++)
//	{
//		int ret = Func1(i);
//		if (ret == i)
//			num++;
//	}
//
//	if (num != 0)
//		return num;
//	else
//		return -1;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << count(n) << endl;
//	system("pause");
//	return 0;
//}

class A 
{
public:
	 void f()    { printf("A\n"); }
};
class B : public A
{
public:
	virtual void f()    { printf("B\n"); } 
};

int main()
{
	A *a = new B;
	a->f();
	delete a;
	system("pause");
	return 0;
}