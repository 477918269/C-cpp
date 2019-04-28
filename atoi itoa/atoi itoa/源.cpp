#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>

using namespace std;
int my_atoi(const char* str)
{
	int cur = 0;
	const char* pur = str;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '0')
	{
		if (*str > '9' || *str < '0')
			break;

		if (*str >= '0' && *str <= '9')
		{
			cur = cur * 10 + *str - '0';
		}
		str++;
	}
	if (*pur == '-')
		return cur * -1;
	return cur;
}

char* my_itoa(int n, char str[])
{
	int count = n;
	int i = 0;
	if (count < 0)
	{
		n = -n;
	}

	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}

	if (count < 0)
	{
		str[i++] = '-';
	}

	str[i] = '\0';
	for (int j = i - 1, i = 0; j > i; j--, i++)
	{
		str[j] ^= str[i];
		str[i] ^= str[j];
		str[j] ^= str[i];

	}
	return str;

}

void Test()
{
	char s[] = "12345";
	int c = my_atoi(s);
	cout << c << endl;
}

void Test1()
{
	int a = 12345;
	char s[25];

	char* s1 = my_itoa(123, s);
	printf("%s", s1);

}


int main()
{
	Test1();

	system("pause");
}