#include<iostream>

using namespace std;

struct A
{
	char    a : 2;
	char    b : 3;
	char    c : 1;
};

struct B
{
	char    a : 2;
	char    b : 3;
	char    c : 7;
};

struct C
{ 
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};

struct D 
{
	char    a : 2;
	char    b : 8;
	int		c : 1;
};

struct E
{
	int i : 8;
	int j : 4;
	double b;
	int a : 3;
};

struct F
{
	int i : 8;
	int j : 4;
	char b : 1;
	int a : 3;
};

int main()
{
	printf("%d\n", sizeof(A));
	printf("%d\n", sizeof(B));
	printf("%d\n", sizeof(C));
	printf("%d\n", sizeof(D));
	printf("%d\n", sizeof(E));
	printf("%d\n", sizeof(F));



	system("pause");
}