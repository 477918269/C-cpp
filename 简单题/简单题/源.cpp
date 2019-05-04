class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string s;
		if (strs.empty())
			return s;

		for (int i = 0; i < strs[0].size(); i++)
		{
			s += strs[0][i];
		}
		int num = 0;

		for (int i = 0; i < strs.size(); i++)
		{
			num = num < strs[i].size() ? num : strs[i].size();
		}

		for (int i = 1; i < strs.size(); i++)
		{
			string s1;
			for (int j = 0; j < num; j++)
			{
				if (s[j] != strs[i][j])
				{
					s = s1;
					break;
				}
				s1 += strs[i][j];
			}
		}
		return s;
	}
};