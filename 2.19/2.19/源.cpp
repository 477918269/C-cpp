#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>

using namespace std;

//实现mystrlen，mystrcpy,strcat,strcmp,strstr

int mystrlen1(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int mystrlen2(char* str)
{
	if (*str == NULL)
		return 0;
	else
		return 1 + mystrlen2(str+1);
}
//会将源字符串中的 '\0' 拷贝到目标空间
//目标空间必须要有足够的空间

void mystrcpy(char* str, const char* cstr)
{
	if (strlen(str) < strlen(cstr))
		return;
	while (*cstr)
	{
		*str++ = *cstr++;
	}
	*str = '\0';
}

void mystrcat(char* str, const char* ystr)
{
	while (*str)
	{
		str++;
	}
	while (*ystr)
	{
		*str++ = *ystr++;
	}
	*str = '\0';
}

int  mystrcmp(const char* str1, const char* str2)
{
	if (strlen(str1) > strlen(str2))
		return 1;
	else if (strlen(str1) < strlen(str2))
		return -1;
	else
	{
		const char* cp = str1;
		const char* cp1 = str2;
		while (*cp && *cp1 && *cp == *cp1)
		{

			if (*cp > *cp1)
				return 1;
			if (*cp < *cp1)
				return -1;
			cp++;
			cp1++;
		}
		return 0;
	}
}

char* mystrstr(const char* str1, const char* str2)
{
	char* cur = (char*)str1;
	while (*cur)
	{
		char* cp = cur;
		char* pur = (char*)str2;
		while (*cp && *pur && *cp == *pur)
		{
			*cp++;
			*pur++;
		}
		if (*pur == '\0')
		{
			return cur;
		}
		cur++;
	}
	return 0;
}

int main()
{
	char s[] = "abbcdef";
	char s1[] = "bc";
	//int cut = strlen(s);
	
	//int cut = strlen(s);
	//int cut = mystrlen2(s);
	cout << mystrstr(s, s1);
	system("pause");
	return 0;
}