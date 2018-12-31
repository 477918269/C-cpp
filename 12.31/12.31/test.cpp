#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d", n%10);
}
int main()
{
	int num = 1234;
	print(num);
	scanf("%d", num);

	
	return 0;
}