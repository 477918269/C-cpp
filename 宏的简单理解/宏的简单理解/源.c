#include<stdio.h>
#include<stdlib.h>

//#define Add(a,b) ((a) + (b))

#define Swap(x,y)\
	x = x + y;\
	y = x - y;\ 
	x = x - y;


int main()
{
	//int c = Add(1, 2) * 3;
	//printf("%d\n", c);
	int x = 1;
	int y = 3;
	Swap(x, y);
	//int a = Add(x | y, x & y);
	printf("x = %d y = %d\n", x, y);
	system("pause");
	return 0;
}

