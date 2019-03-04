#include<iostream>
#include<list>
#include <algorithm>
using namespace std;

void Test1()
{
	list<int> ll;
	list<int> l2(10, 3);
	list<int> l3(l2.begin(), l2.end());
	list<int> copy(l2);

	list<int> ::iterator copyit = copy.begin();
	while (copyit != copy.end())
	{
		cout << *copyit << " ";
		copyit++;
	}
	cout << endl;
}

void Test2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);                
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	auto pos = find(l.begin(), l.end(), 3);
	if (pos != l.end())
	{
		l.insert(pos, 30);
	}

	list<int> ::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	Test2();
	system("pause");
	return 0;
}