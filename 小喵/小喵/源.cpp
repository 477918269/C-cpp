#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		for (int i = 0; i < s2.size(); i++)
		{
			s2[i] *= 7.28;
		}
		if (s1 > s2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}



	return 0;
}