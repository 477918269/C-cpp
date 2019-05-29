#include<iostream>
#include<vector>
using namespace std;



int WhatFuck(vector<vector<int>> vv, int i, int j, int n, int m, int& num)
{
	if (vv[vv.size() - 1][vv[i].size() - 1] == 1)
		return ++num;

	if (j < vv[i].size() - 1 && vv[i][j + 1] == 0)
	{
		vv[i][j + 1] = 1;
		WhatFuck(vv, i, j + 1, n, m, num);
	}
	if (i < vv.size() - 1 && vv[i + 1][j] == 0)
	{
		vv[i + 1][j] = 1;
		WhatFuck(vv, i + 1, j, n, m, num);
	}

	return num;

}

int main()
{
	int n, m;
	cin >> n >> m;
	int k = n;
	int l = m;
	n += 1;
	m += 1;
	vector<int> v;
	vector<vector<int>> vv;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			v.push_back(0);
		}
		vv.push_back(v);
		v.clear();
	}
	int num = 0;
	cout << WhatFuck(vv, 0, 0, l, k, num) << endl;
	system("pause");
	return 0;
}