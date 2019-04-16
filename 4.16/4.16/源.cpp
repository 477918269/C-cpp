#include<iostream>
#include<vector>
#include<string>
using namespace std;
//
//bool Su(int i)
//{
//	int a[] = { 2, 3, 5, 7, 11, 13, 15, 17, 19, 21, 23, 31 };
//	for (int j = 0; j < sizeof(a) / sizeof(a[0]); j++)
//	{
//		if (i == a[j])
//			return 1;
//	}
//
//
//	return 0;
//}
//
//int countPrimeSetBits(int L, int R)
//{
//	int num = 0;
//	for (int i = L; i <= R; i++)
//	{
//		int count = 0;
//		int j = i;
//		while (j)
//		{
//
//			j = (j & (j - 1));
//			count++;
//		}
//		if (Su(count))
//			num++;
//	}
//	return num;
//}
//
//int main()
//{
//	int a = 289051;
//	int b = 294301;
//	Su(3);
//	int cur = countPrimeSetBits(a, b);
//	cout << cur;
//	system("pause");
//}

vector<string> v;

void fun(string s, int i)
{
	if (s.size() == i)
	{
		v.push_back(s);
		return;
	}
	fun(s, i + 1);

	if (s[i] >= 'a' && s[i] <= 'z')
	{
		s[i] = s[i] - 'a' + 'A';
		fun(s, i + 1);
	}
	else if (s[i] >= 'A' && s[i] <= 'Z')
	{
		s[i] = s[i] - 'A' + 'a';
		fun(s, i + 1);
	}

}

vector<string> letterCasePermutation(string S)
{
	fun(S, 0);
	return v;

}

int main()
{
	string s("a1b2");
	letterCasePermutation(s);
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		it++;
	}
	system("pause");

}