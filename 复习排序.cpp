void intercept()
{
	vector<int> missile = { 389, 207, 155, 300, 299, 170, 158, 65 };
	int len = missile.size();
	vector<int> note(len);
	for (int i = 0; i < len; i++)
		note[i] = 0;//note表初始化

	for (int i = len - 1; i >= 0; i--)//从最后一个导弹开始向前分析
	{
		int max = 0, flag = i;//max表示向后查询记录表note时，当前查询到的最多可拦截导弹数量，flag表示当前查到的最大数量导弹的下标
		cout << "i=" << i << endl;
		for (int j = i + 1; j < len; j++)
		{
			if (missile[i] > missile[j] && note[j] > max)//当当前导弹高度大于之后第j个导弹高度，且第j个导弹之后可拦截最多数量大于目前已知最大数量时候，更新flag和max；
			{
				flag = j;
				max = note[j];
			}
		}
		note[i] = note[flag] + 1;
		for (auto x : note)
			cout << x << " ";
		cout << endl;
	}

	return;
}
