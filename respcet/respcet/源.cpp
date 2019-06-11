#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	string strs[] = { "Æ»¹û", "Æ»¹û", "·¬ÇÑ", "·¬ÇÑ", "Æ»¹û", "éÙ×Ó", "Àæ" };
	map<string, int> mp;
	for (const auto& e : strs)
	{
		mp[e]++;
	}
	for (auto e : mp)
	{
		cout << e.first<< " " << e.second << endl;
	}
	system("pause");
	return 0;
}