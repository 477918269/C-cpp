#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

//int main()
//{
//	//string s;
//	//stringstream ss;
//	//int n;
//	//cout << "输入一个整数" << endl;
//	//cin >> n;
//	//n = n * 2 + 1;
//	//ss << n;
//	//ss >> s;
//	//cout << "输出转换后得到的字符串：" << endl;
//	//cout << s << endl;
//	int res;
//	string s("10");
//	stringstream out;
//	out << s;
//	out >> res;
//	cout << res;
//	system("pause");
//}


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> v;
		stack<int> s;

		for (int i = 0; i < nums2.size(); i++)
		{
			s.push(nums2[i]);
		}
		int count;
		for (int j = 0; j < nums1.size(); j++)
		{
			stack<int> ss(s);

			count = -1;
			while (!ss.empty())
			{
				if (ss.top() > nums1[j])
					count = ss.top();
				else if (ss.top() == nums1[j])
					break;
				ss.pop();
			}

			v.push_back(count);

		}
		return v;

	}

int main()
{
	vector<int>a;
	a.push_back(4);
	a.push_back(1);
	a.push_back(2);

	vector<int>b;
	b.push_back(1);
	b.push_back(3);
	b.push_back(4);
	b.push_back(2);

	nextGreaterElement(a, b);
	return 0;
}