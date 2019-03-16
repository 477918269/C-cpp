#include<iostream>

using namespace std;

int RealKey(int* a, int begin, int end)
{
	int mid = begin + (end - begin) >> 1;
	if (a[mid] > a[begin])
	{
		if (a[begin] > a[end])
			return begin;
		else if (a[end] > a[mid])
			return mid;
	}
	if (a[mid] > a[end])
	{
		if (a[begin] > a[mid])
		{
			return mid;
		}
		else if (a[end] > a[begin])
		{
			return end;
		}
	}
	return begin;
}

int FastBuild1(int* a, int begin, int end)
{
	int key = RealKey(a, begin, end);

	swap(a[key], a[begin]);
	while (begin < end)
	{
		
		while (begin < end && a[end] > a[key])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}

		swap(a[begin], a[end]);
	}
	swap(a[key], a[begin]);
	return begin;

}

int FastBuild2(int* a, int begin, int end)
{
	int key = RealKey(a, begin, end);
	int newkey = a[key];
	swap(a[begin], a[key]);
	while (begin < end)
	{
		while (begin < end && a[end] > newkey)
		{
			end--;
		}
		a[begin] = a[end];

		while (begin < end && a[begin] <= newkey)
		{
			begin++;
		}

		a[end] = a[begin];
	}
	a[begin] = newkey;
	return begin;
}

int FastBuild3(int* a, int begin, int end)
{
	int cur = begin + 1;
	int pur = begin;
	int sad = begin;
	while (cur != end)
	{
		if (a[sad] > a[cur] && pur++ != cur)
		{
			swap(a[sad], a[cur]);
		}
		cur++;
	}
	swap(a[sad], a[pur]);
	return pur;
}

void FastSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int div = FastBuild1(a, begin, end);
	FastSort(a, begin, div - 1);
	FastSort(a, div + 1, end);
}

int main()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(a) / sizeof(a[0]);
	int begin = 0;
	int end = n - 1;
	FastSort(a, begin, end);
	for (auto e : a)
	{
		cout << e << " ";
	}
	
	system("pause");
	return 0;
}