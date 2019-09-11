//#include<stdio.h>
//#include<assert.h>
//
//void* my_memset(void* s, int ch, size_t n)
//{
//	if (s == NULL || n <= 0)
//		return NULL;
//
//	char* tmp = (char*)s;
//	while (n--)
//	{
//		*tmp++ = ch;
//	}
//	return tmp;
//}
//
//void* my_memcpy(void* dest, void* str, size_t n1)
//{
//	assert(*dest != NULL);
//	assert(*str != NULL);
//
//	int num = n1 / strlen(str);
//	int slice = n1 % strlen(str);
//
//	unsigned long* s = (unsigned long*)dest;
//	unsigned long* u = (unsigned long*)str;
//
//
//	while (num--)
//	{
//		*s++ = *u++;
//	}
//
//	while (slice--)
//	{
//		*(char*)s++ = *(char*)u++;
//	}
//	return dest;
//
//
//}
//
//void* my_memmove(void* dest, void* str, size_t n)
//{
//	void* ret = dest;
//
//	if (*dest <= *str || (char*)dest >= (char*)str + n)
//	{
//		while (n--)
//		{
//			*(char*)dest = *(char*)str;
//			dest = (char*)dest + 1;
//			str = (char*)str + 1;
//		}
//	}
//	else
//	{
//		dest = (char*)dest + n - 1;
//		str = (char*)str + n - 1;
//		while (n--)
//		{
//			*(char*)dest = *(char*)str;
//			dest = (char*)dest - 1;
//			str = (char*)str - 1;
//		}
//	}
//	return ret;
//
//}