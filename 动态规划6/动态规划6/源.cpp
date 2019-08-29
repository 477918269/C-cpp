#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	vector<int> table = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };//方便理解，数组下标从1开始，0补位 C++11新标准vector初始化方式
	int n;
	cin >> n;//输入钢条长度
	vector<int> r(n + 1, 0);//方便理解，数组下标从1开始，初始化11位数组
	for (int i = 1; i <= n; i++)
	{
		int max = -1;
		for (int j = 1; j <= i; j++)
		{
			if (max < table[j] + r[i - j])
				max = table[j] + r[i - j];
		}
		r[i] = max;
	}
	for (auto x : r)
		cout << x << " ";
	cout << endl;
	return 0;
}