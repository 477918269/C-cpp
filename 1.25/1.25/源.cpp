#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

void Test1()
{
	vector<int> a;
	vector<int> b(5,8);
	vector<int> c(b.begin(), b.end());
	vector<int> d(b);

	vector<int>::iterator it = b.begin();
	while (it != b.end())
	{
		cout << *it;
		++it;
	}
}

int main()
{
	Test1();
	system("pause");
	return 0;
}
