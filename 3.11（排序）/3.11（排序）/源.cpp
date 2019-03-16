#include<iostream>

using namespace std;

void ChaSort()
{
	int a[] = { 5, 2, 4, 6, 1, 3 };
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		int j = i;
		if (i + 1 != sizeof(a) / sizeof(a[0]) && a[i] < a[i + 1])
		{
			swap(a[i], a[i + 1]);
		}
		while (j != 0 && a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			j--;
		}
	}

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}

void XerSort()
{
	int a[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
	int len = sizeof(a) / sizeof(a[0]);
	int gap = 5;
	
	while (gap > 1)
	{
		gap = (gap / 3) + 1;
		for (int i = 0; i < len - gap; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (a[j] > a[j + gap])
				{
					swap(a[j], a[j + gap]);
					j -= gap;
				}
				else
					break;
			}
		}
		
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}

} 
int main()
{
	//ChaSort();
	XerSort();


	system("pause");
	return 0;
}