#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		v[0] = 1;
		v[1] = 0;
		int sum = v[0] + v[1];
		for (int i = 2; i < n; i++)
		{
			v[i] = v[i - 1] + v[i - 2];
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;

bool match_string(const char* s, const char* s1)
{
	if (*s == '\0' && *s1 == '\0')
		return true;
	if (*s == '\0' || *s1 == '\0')
		return false;

	if (*s == '?')
		return match_string(s + 1, s1 + 1);
	else if (*s == '*')
		return match_string(s + 1, s1) || match_string(s + 1, s1 + 1) || match_string(s, s1 + 1);
	else if (*s == *s1)
		return match_string(s + 1, s1 + 1);

	return false;
}

int main()
{
	string s, s1;
	while (cin >> s >> s1)
	{
		bool res = match_string(s.c_str(), s1.c_str());
		if (res == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}