#include<iostream>
#include<string>

using namespace std;
//void Test()
//{
//	string s("hellow world");
//	string::iterator it = s.begin();
//	
//	while (it != s.end())//迭代器用法(所有容器都可以使用)
//	{
//		cout << *it << endl;
//		it++;
//	}
//
//	for (auto ch : s) //范围for(所有容器都可以使用,底层依赖迭代器)
//	{
//		cout << ch << " ";
//	}
//
//	string::reverse_iterator rit = s.rbegin();//用迭代器反着输出
//	while (rit != s.rend)
//	{
//		cout << *rit << " ";
//		it++;
//	}
//	string::const_iterator it = s.begin();//输出const形
//	string::const_reverse_iterator it = s.rbegin();//反向输出const形
//	//4种迭代器，正向，反向，const型正向，const型反向
//	//C++11： s.cbegin s.cend,s.crbegin,s.crend.
//
//	//增空间是k/2倍的增
//
//	//reserve可以提高扩容效率
//	//s.reserve
//		//resize可以改变size的大小
//
//		//s.resize;
//}
void Test1()
{
	string s("123");
	int num = atoi(s.c_str);
	cout << num << endl;
}
//string::npos = -1;


void Test2()
{
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t pos = url.find("://");

}
int main()
{
	Test1();
	system("pause");
	return 0;
}