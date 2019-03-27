#include<iostream>
#include<vector>
#include<string>
using namespace std;

//int main()
//{
//	vector<string> v;
//	v.push_back("a");
//	v.push_back("b");
//	v.push_back("c");
//	v.push_back("d");
//	v.push_back("e");
//	v.push_back("f");
//	vector<string> ::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it;
//		it++;
//	}
//
//	system("pause");
//	return 0;
//}

int main()
{
	int a[] = { 1, 2 };
	a[0] = a[1];
	printf("%d", a[1]);
	system("pause");
}