#include<iostream>
#include<string>
using namespace std;

//template<class T>

//bool IT(T& left, T& right)
//{
//	return left == right;
//}
//template<>
//bool ssd<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return true;
//	return false;
//}
//int main()
//{
//	char* ptr1 = "hello";
//	char* ptr2 = "world";
//	if (ssd(ptr1, ptr2))
//		cout << ptr1 << endl;
//	else
//		cout << ptr2 << endl;
//	system("pause");
////}

template<class T1, class T2>
class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

template<>
class Date<int, char>
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
private:
	T _d1;
	T _d2;
};

int main()
{
	Date<int, int> d1;
	Date<int, char>d2;
}