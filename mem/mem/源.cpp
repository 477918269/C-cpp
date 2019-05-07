#include<iostream>
#include<stdio.h>
#include<string.h>

//一般版本,这里把dest和src都强制转换成了（char*）类型，但是copy一定是一个个字节完成的吗?（打算先拿这个版本给面试官看看）
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert((NULL != dest) && (NULL != source));
//	char* tmp = (char*)dest;
//	const char* cur = (char*)src;
//
//	while (count--)
//		*tmp++ = *cur++;
//
//	return dest;
//}

//最终版本，不考虑内存重叠的情况下。
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	//assert((NULL != dest) && (NULL != source));
//
//	int num = count / sizeof(dest);//按dest类型拷贝
//	int slice = num % sizeof(dest);//剩余字节拷贝
//
//	unsigned long * s = (unsigned long*)src;
//	unsigned long * d = (unsigned long*)dest;
//
//	while (num--)
//		*d++ = *s++;
//
//	while (slice--)
//		*((char*)d++) = *((char*)s++);
//
//	return dest;
//
//}
//最终版本，考虑内存重叠问题

void* my_memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	//dst <= src表示，如果dst在src的前面，从前往后复制不会覆盖src中还没有复制的内容

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		//从前往后复制，则不会出现覆盖src中没有复制的内容
		while (count--)
		{
			*(char*)dst = *(char*)src; //char类型指针，表示一个字节一个字节的复制
			dst = (char*)dst + 1; //移动一个字节
			src = (char*)src + 1;
		}
	}
	else
	{
		//从后往前复制，则不会出现覆盖src中没有复制的内容
		dst = (char*)dst + count - 1;//移动到末尾
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1; //移动一个字节
			src = (char*)src - 1;
		}
	}
	//返回dst的头指针，还方便左值操作。
	//如：ptstr = memmove(ptstr,src,count); cout << memmove(ptstr,src,count);
	return ret;
}

int main()
{
	char s[] = "abcdefghijk";
	my_memcpy(s, s + 4, 4);
	printf("%s", s);
	system("pause");
	return 0;
}