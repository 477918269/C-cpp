#include<iostream>

using namespace std;

int main()
{
	string str1 = "a";
	string str3 = "b";
	string &str2 = str1;
	&str2 = str3;
	system("pause");
	}