#include<iostream>
#include<vector>
using namespace std;

//void _MergeSort(vector<int>& v, int begin, int end, vector<int>& v1)
//{
//	if (begin >= end)
//		return;
//	int mid = begin + ((end - begin) >> 1);
//
//	_MergeSort(v, begin, mid, v1);
//	_MergeSort(v, mid + 1, end, v1);
//
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int index = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (v[begin1] > v[begin2])
//			v1[index++] = v[begin1++];
//		else
//			v1[index++] = v[begin2++];
//
//	}
//
//	while (begin1 <= end1)
//	{
//		v1[index++] = v[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		v1[index++] = v[begin2++];
//	}
//
//
//	index = begin;
//	while (end >= begin)
//	{
//		v[index++] = v1[begin++];
//	}
//}

//void MergeSort(vector<int>& v)
//{
//	vector<int> v1(v.size(), 0);
//	_MergeSort(v, 0, v.size() - 1, v1);
//}

int QuickSort(vector<int>& v, int begin, int end)
{
	int key = begin;
	
	while (begin < end)
	{
		while (begin < end && v[end] > v[key])
			end--;
		while (begin < end && v[begin] <= v[key])
			begin++;
		swap(v[begin], v[end]);
	}
	swap(v[key], v[begin]);
	return begin;
}

void QuickBuild(vector<int>& v, int begin, int end)
{
	if (begin >= end)
		return;
	int div = QuickSort(v, begin, end);
	QuickBuild(v, begin, div - 1);
	QuickBuild(v, div + 1, end);
}

int main()
{
	vector<int> v;
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };

	for (auto e : a)
	{
		v.push_back(e);
	}
	QuickBuild(v, 0, v.size() - 1);
	//MergeSort(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	system("pause");
	return 0;
}