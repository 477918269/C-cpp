#include<iostream>

using namespace std;

void fun(int)
{
	cout << "f(int)" << endl;
}

void fun(int*)
{
	cout << "f(int*)" << endl;
}


int main()
{
	//fun(0);
	//fun(NULL);
	//fun((int*)NULL);

	printf("%d\n", sizeof(nullptr));
	printf("%d\n", sizeof((void*)0));

	system("pause");
	return 0;
}