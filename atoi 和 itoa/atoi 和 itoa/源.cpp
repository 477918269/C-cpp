#include<iostream>
#include<string>

using namespace std;
int my_atoi(const char* str)
{
	int cur = 0;
	const char* num = str;
	if (*str == '+' || *str == '-')
		str++;

	while (*str)
	{
		if (*str > '9' || *str < '0')
			break;
		if (*str >= '0' && *str <= '9')
		{
			cur = cur * 10 + *str - '0';
		}
		str++;
	}

	if (*num == '-')
	{
		cur *= -1;
	}

	return cur;
}

char* my_itoa(int num, char str[])
{
	int n = 0;
	int count = n;
	if (count < n)
	{
		num = -num;
	}

	while (num)
	{
		str[n++] = num % 10 + '0';
	}

	if (count < 0)
	{
		str[n++] = '-';
	}

	str[n] = '\0';

	for (int j = n - 1, i = 0; j > i; i++, j--)
	{
		str[j] ^= str[i];
		str[i] ^= str[j];
		str[j] ^= str[i];
	}
	return str;
}

char* my_itoa2(int n, char str[], int index)
{
	string _itoa = "";
	int i = 0;
	int num = n;
	unsigned int tmp;
	if (n < 0)
	{
		tmp = INT_MIN + n + 1;
		do
		{
			str[i++] = _itoa[n % 10];
		} while ((tmp /= 10) > 0);
	}
	else
	{
		do
		{
			str[i++] = _itoa[n % 10];
		} while ((n /= 10) > 0);
	}
	if (num < 0)
	{
		str[i++] = '-';
	}
	str[i] = '\0';

	for (int j = n - 1, i = 0; j > i; i++, j--)
	{
		str[j] ^= str[i];
		str[i] ^= str[j];
		str[j] ^= str[i];
	}
	return str;
}

void Test()
{
	string s("123k4");
	int c = my_atoi(s.c_str());//先将string类型转换为char*类型，再通过atoi函数将字符数字转换为整形数字
	cout << c << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}