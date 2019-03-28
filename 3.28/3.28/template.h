#pragma once

template<class T>
T Add(const T& a, const T& b);//ÏÔÊ¾ÊµÀı»¯

int add(int a, int b);

template
int Add<int>(const int& a, const int&b);

template<class T>
T Add(const T&a, const T&b)
{
	return a + b;
}
