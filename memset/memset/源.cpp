#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

void* my_memset(void* s, int ch, size_t n)
{
	if (s == NULL || n < 0)
		return NULL;

	char* tmp = (char*)s;
	while (n--)
	{
		*tmp++ = ch;
	}
	return s;
}

int main()
{
	char s[] = {1,2,3,4,5};


	my_memset(s, 0, 6);
	for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
	{
		printf("%d", s[i]);
	}
	system("pause");
	return 0;
}