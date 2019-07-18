#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		reverse(s.begin(), s.end());
		string s2;
		int i = 0;
		int j = 0;
		while (i < s.size())
		{
			int k = s.find(' ', j);
			string s1 = s.substr(i, k);
			reverse(s1.begin(), s1.end());
			s2 += s1;
			i = k + 1;
			j = i + 1;

		}
	}

	cout << s << endl;

	system("pause");
	return 0;
}