#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		string s1;
		int i = 0;
		while (i < s.size() - 1)
		{
			int j = i;
			string s2;
			while (s[j] == s[j + 1] && j < s.size() - 1)
			{

				s2 += s[j];
				j++;
			}
			s2 += s[j];
			if (s2.size() > s1.size())
			{
				s1 = s2;
			}
			i++;
		}
		cout << s1 << endl;
	}
	return 0;
}