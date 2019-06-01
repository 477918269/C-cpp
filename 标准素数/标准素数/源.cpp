//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<int> v;
//		for (int i = 3; i < n; i++)
//		{
//			int j = 2;
//			for (; j < i; j++)
//			{
//				if (i % j == 0)
//					break;
//			}
//			if (j == i || i == 3)
//				v.push_back(i);
//		}
//
//		int k = (v.size() - 1) / 2;
//		int l = k + 1;
//		while (l < v.size() || k >= 0)
//		{
//			if (v[k] + v[l] > n)
//				k--;
//			else if (v[k] + v[l] < n)
//				l++;
//			else
//			{
//				cout << v[k] << endl;
//				cout << v[l] << endl;
//				break;
//			}
//
//		}
//
//
//	}
//	system("pause");
//	return 0;
//}

//#include "stdio.h"
//#define N 9
//int x[N];
//int count = 0;
//
//void dump()
//{
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{ 
//		printf("%d", x[i]);
//	}
//	printf("\n");
//}
//void swap(int a, int b)
//{
//	int t = x[a];
//	x[a] = x[b];
//	x[b] = t;
//}
//void run(int n)
//{ 
//	int i;
//	if (N - 1 == n)
//	{ 
//		dump();
//		count++;
//		return;
//	}
//	for 
//		(i = ___; i < N; i++) { swap(___, i);    run(n + 1);    swap(___, i); } }
//int main() { int i;  for (i = 0; i < N; i++) { x[i] = i + 1; }  run(0);  printf("* Total: %d\n", count); }

#include<iostream>

using namespace std;

//class A 
//{
//public:
//	void foo()    { printf("1"); }
//	virtual void fun()    { printf("2"); }
//}; 
//class B : public A
//{
//public:
//	void foo()    { printf("3"); }
//	void fun()    { printf("4"); }
//};
//int main(void)
//{
//	A a;
//	B b;
//	A *p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A *ptr = (A *)&b;
//	ptr->foo();
//	ptr->fun();
//	system("pause");
//	return 0;
//}
class A 
{ 
public:
	virtual void func(int val = 1)
	{ std::cout << "A->" << val << std::endl; }
	virtual void test()    { func(); }
};
class B : public A 
{
public:
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	system("pause");
	return 0;
}
