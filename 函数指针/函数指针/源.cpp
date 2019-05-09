#include<iostream>

using namespace std;

int Add(int a, int b)
{
	return a + b;
}

int main()
{
	//char* fun(char* p1, char* p2)// 1
	//char** fun(char* p1, char* p2);// 2
	//char*(*fun)(char* p1, char* p2);// 3

	int(*fun1)(int a, int b);
	fun1 = &Add;
	cout << fun1(1, 2) << endl;
	

	system("pause");
	return 0;

}