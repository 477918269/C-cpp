#include<iostream>
#include<map>
#include<string>
using namespace std;

void Test()
{
	map<string, string> m{
		{ "apple", "苹果" },
		{ "banan", "香蕉" },
		{ "orange", "橘子" },
		{ "peach", "桃子" },
		{ "waterme", "水蜜桃" } };
	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << it->second << endl;
		it++;
	}
}

void Test1()
{
	map<string, string> m{
		{ "apple", "苹果" },
		{ "banan", "香蕉" },
		{ "orange", "橘子" },
		{ "peach", "桃子" },
		{ "waterme", "水蜜桃" } };

	cout << m["apple"] << endl;
	cout << m["peach"] << endl;
	map<string, string> m1(m);

}

void Test2()
{
	map<string, long long> m;
	m["abc"] = 2;

	cout << m["abc"] << endl;
	cout << m.size() << endl;
}

void Test3()
{
	map<string, string> m;
	m.insert(pair<string, string>("peach", "桃子"));
	m.insert(pair<string, string>("apple", "苹果"));

	m["orange"] = "橘子";
	
	m.insert(m.find("banana"), make_pair("waterme", "水蜜桃"));
	cout << m.size() << endl;

	for (auto& e : m)
		cout << e.first << ":" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("peach", "桃色"));

	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" << ret.first->second\
		<< " 插入失败" << endl;

	m.erase("apple");
	for (auto& e : m)
		cout << e.first << ":" << e.second << endl;


}


void Test4()
{
	multimap<string, string> m{
		{ "apple", "苹果" },
		{ "banan", "香蕉" },
		{ "orange", "橘子" },
		{ "peach", "桃子" },
		{ "waterme", "水蜜桃" } };

	m.insert(make_pair("apple", "红苹果"));
	cout << m.size() << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void Test5()
{
	multimap<int, int> m;

	for (int i = 0; i < 10; ++i)
		m.insert(make_pair(i, i));

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	Test5();
	system("pause");
}
