//前后指针的快速排序
int QuickBuilt3(int*a, int begin, int end)//两个指针排序
{
	int cur = begin + 1;
	int prev = begin;
	int key = begin;
	while (cur <= end)
	{
		if (a[cur] < a[key] && ++prev != cur)//注意&&是两个为真才为真，前后的判断都是要实现的。
		{
			int tmp = a[prev];
			a[prev] = a[cur];
			a[cur] = tmp;
		}
		cur++;
	}
	int tme = a[prev];
	a[prev] = a[key];
	a[key] = tme;

	return prev;
}

void ShellNode(int* a, int n)
{
	int gap = 5;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i<n - gap; i++)
		{

			int end = i;
			while (end >= 0)
			{
				if (a[end] > a[end + gap])
				{
					int tmp = a[end];
					a[end] = a[end + gap];
					a[end + gap] = tmp;
					end -= gap;
				}
				else
				{
					break;
				}

			}
		}
	}
}