//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	char s = 129;
//	printf("%d\n", s);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
int main()
{
	char a = -1;
	unsigned char b = -1;
	char c = a + b;
	printf("sizeof(c):%d\n", sizeof(c));
	printf("sizeof(a+b):%d\n", sizeof(a + b));
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("c:%d", c);
	getchar();
	return 0;
}
