#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
//解决斐波那契数
//int FB(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return FB(n - 1) + FB(n - 2);
//}
//
//int main()
//{
//	int num = 0;
//	int poi = 0;
//	printf("请输入你要的查找的第N位斐波那契数>:");
//	scanf("%d", &num);
//	poi = FB(num);
//	printf("%d", poi);
//
//	system("pause");
//	return 0;
//}

//解决汉诺塔问题
//void move()
//{
//	printf("form %d to %d ")
//}
//
//int Honio(int n)
//{
//	if (n = 1)
//	{
//		move()
//	}
//	else
//
//}
//
//int main()
//{
//	int n = 0;
//	
//	printf("请输入你要搬运的木块");
//	scanf("%d", &n);
//
//	char 
//	system("pause");
//
//	return 0;
//}

//青蛙跳台阶问题
//第一问：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//和斐波那契函数一样，当n>3时用递归。
//但是，如果数非常大，需要用循环代替递归。
//如下：
//int FB(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = a+b;
//	int i = 0;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		for (i = 3; i < n; i++)
//		{
//			b = a;
//			a = c;
//			c = a + b;
//		}
//		return c;
//	}
//	
//}
//
//int main()
//{
//	int num = 0;
//	int poi = 0;
//	printf("请输入N个台阶>:");
//	scanf("%d", &num);
//	poi = FB(num);
//	printf("%d", poi);
//
//	system("pause");
//	return 0;
//}

//第二问：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//		  求该青蛙跳上一个n级的台阶总共有多少种跳法。
//思路：n=1 , f(n)只有一次跳一个台阶，1种方法；
//		n=2 , f(n)第一次跳一个台阶，1种，第一次跳两个台阶，1种
//		n=3 , f(n)第一次跳一个台阶，f(3-1)种，第一次跳两个台阶，f(3-2)种，第一次跳三个台阶, 1种
//		f(n) = f(n-1)+f(n-2)+...+1
//		f(n-1) = f(n-2) +f(n-3)+...+1
//		f(n) - f(n - 1) = f(n - 1);
int FB(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return 2 * FB(n - 1);
}
int main()
{
		int num = 0;
		int poi = 0;
		printf("请输入你需要的台阶>:");
		scanf("%d", &num);
		poi = FB(num);
		printf("%d", poi);
	
		system("pause");
		return 0;
	return 0;
}
