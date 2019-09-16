#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;

//void ChooseShort(vector<int>& v)
//{
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = i; j < v.size(); j++)
//		{
//			swap(v[i], v[j]);
//		}
//	}
//}

//void HeapBuild(vector<int> & v, int i, int n)
//{
//	int parent = i;
//	int child = i * 2 + 1;
//
//	while (child < n)
//	{
//		if (child + 1 < n && v[child + 1] < v[child])
//			child++;
//		if (v[parent] > v[child])
//		{
//			swap(v[child], v[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}
//
//void HeapSort(vector<int>& v)
//{
//	int n = v.size();
//	for (int i = (n - 2) / 2; i >= 0; i--)
//	{
//		HeapBuild(v, i, n);
//	}
//
//	int end = n - 1;
//	while (end > 0)
//	{
//		swap(v[end], v[0]);
//		HeapBuild(v, 0, end);
//		end--;
//	}
//}

void CountSort(vector<int>& v)
{
	assert(v.empty() == 0);
	int min = v[0];
	int max = v[0];
	int i = 0;
	int n = v.size();
	while (i < n)
	{
		if (min > v[i])
			min = v[i];
		if (max < v[i])
			max = v[i];
		i++;
	}

	int count = max - min + 1;
	vector<int> v1(count, 0);

	for (int i = 0; i < v.size(); i++)
	{
		v1[v[i] - min]++;
	}


	int z = 0;
	int x = 0;
	while (z < v.size())
	{
		while (v1[x]-- > 0)
		{
			v[z++] = x + min;
		}
		x++;
	}
}


int main()
{
	vector<int> v;
	int a[] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	for (auto e : a)
	{
		v.push_back(e);
	}
	CountSort(v);
	//ChooseShort(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}