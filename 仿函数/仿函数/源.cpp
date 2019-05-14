#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//
//class Mul2
//{
//public:
//	void operator()(int& date)
//	{
//		date <<= 1;
//	}
//};
//
//class Mul3
//{
//public:
//	bool operator()(int& date)
//	{
//		return 0 == date % 3;
//	}
//};

int main()
{
	//vector<int> v{ 1, 2, 3, 4, 5, 6 };
	//for_each(v.begin(), v.end(), Mul2());//一般情况下使用的时候都是把first作为容器遍历的起始点指针，last是容器的末尾。重点是functor(仿函数)。
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//auto pos = remove_if(v.begin(), v.end(), Mul3());
	//v.erase(pos, v.end());

	////对于相对功能简单的操作，可以用C++11提供的lambda表示来替代
	////lambda表达式实现简单，其在底层和仿函数相同，编译器会将lambda转换为仿函数

	//for_each(v.begin(), v.end(), [](int date){cout << date << " "; });
	//cout << endl;


	cout << 10 / 10 << endl;
	system("pause");
}