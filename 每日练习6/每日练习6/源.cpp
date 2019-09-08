//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int n = 9;
//	float* f = (float*)&n;
//	printf("n = %d\n", n);
//	printf("f = %f\n", *f);
//
//	*f = 9.0;
//	printf("f = %d\n", n);
//	printf("f = %f\n", *f);
//
//
//	system("pause");
//	return 0;
//}
////int main()
////{
////	int n = 9;
////	float *pFloat = (float *)&n;
////	printf("n的值为：%d\n", n);
////	printf("*pFloat的值为：%f\n", *pFloat);
////	*pFloat = 9.0;
////	printf("num的值为：%d\n", n);
////	printf("*pFloat的值为：%f\n", *pFloat);
////	system("pause");
////	return 0;
////}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v(1, 2, 3, 4);
//
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n = 0;
	string s;
	while (cin >> n >> s)
	{

		if (n <= 4)
		{
			int j = 1;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'U')
				{
					if (j == 1)
					{
						j = n;
					}
					else
						j--;
				}
				else if (s[i] == 'D')
				{
					if (j == n)
					{
						j = 1;
					}
					else
					{
						j++;
					}
				}

			}
			for (int i = 1; i < n; i++)
			{
				cout << i << " ";
			}
			cout << n << endl;
			cout << j << endl;
		}
		else
		{
			int num = 1;
			int first = 1;
			for (int i = 0; i < s.size(); i++)
			{
				if (num == 1 && first == 1 && s[i] == 'U')
				{
					first = n - 3;
					num = n;
				}
				else if (first == n - 3 && num == n && s[i] == 'D')
				{
					first = 1;
					num = 1;
				}
				else if (first != 1 && num == first && s[i] == 'U')
				{
					first--;
					num--;
				}
				else if (first != n - 3 && num == first + 3 && s[i] == 'D')
				{
					first++;
					num++;
				}
				else if (s[i] == 'D')
				{
					num++;
				}
				else
				{
					num--;
				}
			}
			for (int i = first; i < first + 3; i++)
			{
				cout << i << " ";
			}
			cout << first + 3 << endl;
			cout << num << endl;

		}
	}
	return 0;
}
