#include<iostream>

using namespace std;

int main()
{
	string s("http://www.cplusplus.com/reference/string/string/find/");
	int start = s.find("://");
	if (start == string::npos)
	{
		cout << "error" << endl;
		return 0;
	}
	start += 3;
	int finish = s.find('/', start);
	string cur = s.substr(start, finish - start);
	cout << cur.c_str() << endl;
	system("pause");

	return 0;
}