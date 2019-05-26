#include<iostream>
#include<vector>
using namespace std;

int Fibonacci(int i)
{
	if (i == 0)
		return 0;
	if (i < 2)
		return 1;
	return Fibonacci(i - 1) + Fibonacci(i - 2);
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	int i = 0;
	while (Fibonacci(i) < n)
	{
		v.push_back(Fibonacci(i));
		i++;
	}
	v.push_back(Fibonacci(i));

	int num1 = 0;
	int num2 = 0;
	int j = n;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= n)
		{
			break;
		}
	}
	int k = n;
	while (j != v[i])
	{
		num1++;
		j++;
	}
	while (k != v[i - 1])
	{
		num2++;
		k--;
	}
	num1 = num2 < num1 ? num2 : num1;
	cout << num1;
	return 0;
}