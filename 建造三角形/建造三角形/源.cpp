#include<iostream>

using namespace std;

//int main()
//{
//	int a, b, c;
//	while (cin >> a >> b >> c)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}

int Add(int& num1, int num2)
{
	int num = num1 ^ num2;

	int count = (num1 & num2) << 1;

	if (count != 0)
	{
		Add(num, count);
	}
	return num;
}

int main()
{
	Add(5, 6);
	cout << Add(5, 6) << endl;
	system("pause");
	return 0;
}