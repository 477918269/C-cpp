#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string s1;
	string s2;
	while (cin >> s >> s1)
	{

		for (int i = 0; i < (int)s.size(); i++)
		{
			if (s1.find(s[i]) == -1 || s1[i] == ' ')
			{
				s2 += s[i];
			}

		}
		cout << s2 << endl;
	}
	system("pause");
	return 0;
}