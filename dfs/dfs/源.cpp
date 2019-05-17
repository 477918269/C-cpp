#include <iostream>

#include <stdio.h>

#include <cstring>

#include <string>

#include <vector> 

#include <map>

#include <algorithm>

#include <set>

#include <cmath>

#include <math.h>

#include <iomanip>

#include <array>

using namespace std;

int sum_w = 0, sum_v = 0; vector<int> v_temp, v_temp1;//前者存最大得地址 后者是临时存储得地址

int sum_weight(vector<pair<int, int> > v)//计算总重量

{
	int sum1 = 0;

	for (int i = 0; i<v_temp1.size(); ++i)

	{
		sum1 += v[v_temp1[i]].second;
	}

	return sum1;
}

int sum_value(vector<pair<int, int> > v)//计算总价值

{
	int sum1 = 0; for (int i = 0; i<v_temp1.size(); ++i)

	{
		sum1 += v[v_temp1[i]].first;
	}return sum1;
}

void dfs(vector<pair<int, int> > v, int n, int m, int start)//dfs算法

{
	v_temp1.clear();//清空临时存储得地址；

	for (int i = start; i<n; ++i)

	{
		v_temp1.push_back(i);//存入数据

		if (sum_value(v) >= sum_v&&sum_weight(v) <= m)//如果临时容器得地址 与最大价值比较；

		{
			v_temp = v_temp1;//得到最大价值得地址  

			sum_w = sum_weight(v);

			sum_v = sum_value(v);

			 /*  for(int i=0;i<v_temp.size();++i){ cout<<v_temp[i]<<" "<<v_temp[i]<<" ";}cout<<endl;*/ 

		}

		if (sum_w>m)//若质量超过了 则回溯到原地方

		{
			v_temp1.pop_back();//删除最后得地址 

			i = v_temp1[v_temp1.size() - 1];//回溯

			v_temp1.pop_back();//重先选择新的地址

			sum_w = sum_weight(v);    sum_v = sum_value(v);

			v_temp = v_temp1;

			 /*   for(int i=0;i<v_temp.size();++i)     {      cout<<v_temp[i]<<" "<<v_temp[i]<<" ";    }cout<<endl;*/

		}
	}
}

int main(){

	vector<pair<int, int> > v_bag;

	int n, m, t, t1;

	cin >> n >> m;

	cin.get();

	for (int i = 0; i<n; ++i)

	{
		cin >> t >> t1;   	cin.get();   	v_bag.push_back(make_pair(t, t1));
	}

	sort(v_bag.begin(), v_bag.end(), [](const pair<int, int> &x, const pair<int, int> &y)->int{        return x.second>y.second; });

	for (int i = 0; i<n; ++i)//从各个起点开始回溯

	{
		dfs(v_bag, n, m, i);
	}cout << sum_v << " " << sum_w << endl; for (int i = 0; i<v_temp.size(); ++i){ cout << v_bag[v_temp[i]].first << " " << v_bag[v_temp[i]].second << endl; }   return 0;
}
