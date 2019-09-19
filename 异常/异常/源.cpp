#include<iostream>

using namespace std;

void Test()
{
	char* p = new char[0x7fffffff];
}


int main()
{
	try
	{
		Test();
	}
	catch (exception& c)
	{
		cout << c.what() << endl;
	}
	system("pause");
	return 0;
}