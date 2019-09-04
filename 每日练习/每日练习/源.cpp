//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	while (cin >> n)
//	{
//		m = 2 * n - 1;
//		vector<vector<int>> dp(n, vector<int>(m, 0));
//		dp[0][0] = 1;
//		for (int i = 1; i < n; i++)
//		{ //第一列和最后一列都为1
//			dp[i][0] = dp[i][2 * i] = 1;
//			for (int j = 1; j < 2 * i; ++j)
//			{
//				if (j == 1) //如果是第二列，则只是两个元素之和
//					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//				else //第i,j元素等于上一行第j - 2,j - 1,j三列元素之和
//					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
//			}
//		}
//		int k;
//		for (k = 0; k < m; k++)
//		{
//			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
//			{ 
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//		if (k == m)
//			cout << -1 << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//
//	int n, m;
//	while (cin >> n)
//	{
//		m = n * 2 - 1;
//		vector<vector<int>> vv(n, vector<int>(m, 0));
//		vv[0][0] = 1;
//		for (int i = 1; i < n; i++)
//		{
//			vv[i][0] = vv[i][i * 2] = 1;
//			for (int j = 1; j < i * 2; j++)
//			{
//				if (j == 1)
//					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//				else
//				{
//					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
//				}
//			}
//		}
//		int k = 0;
//		for (int k = 0; k < m; k++)
//		{
//			if (vv[n - 1][k] % 2 == 0 && vv[n - 1][k] != 0)
//			{
//				cout << k + 1 << endl;
//				break;
//			}
//		}
//
//		if (k == m)
//			cout << -1 << endl;
//
//
//	}
//	return 0;
//}

//超大正整数

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	cout << a+++++b << endl;
//	return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string AddLongInteger(string s, string s1)
{
	int i = s.size() - 1;
	int j = s1.size() - 1;
	string s2 = "";
	int num = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
		{
			num += s[i] - '0';
		}
		if (j >= 0)
		{
			num += s1[j] - '0';
		}

		s2 += (char)(num % 10 + '0');
		num /= 10;
		i--;
		j--;
	}
	if (num == 1)
	{
		s2 += '1';
	}
	reverse(s2.begin(), s2.end());
	return s2;
}




int main()
{
	string s, s1;

	while (cin >> s >> s1)
	{
		cout << AddLongInteger(s, s1) << endl;
	}

	return 0;
}