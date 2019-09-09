#include<iostream>
#include<vector>
using namespace std;

int Find_Max(int n, int num)
{
	int min = n < num ? n : num;
	int max = 0;
	for (int i = 2; i <= min; i++)
	{
		if (n / i == 0 && num / i == 0)
		{
			max = i;
		}
	}
	return max;
}

int main()
{

	int n, num;
	while (cin >> n >> num)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < v.size(); i++)
		{
			if (num >= v[i])
			{
				num += v[i];
			}
			else
			{
				int j = Find_Max(v[i], num);
				num += j;
			}
		}
		cout << num << endl;
	}


	return 0;
}