class Solution {
public:
	int longestPalindrome(string s)
	{
		int count = 0;
		int flag = 0;
		map<char, int> nums;
		for (int i = 0; i < s.size(); i++)
		{
			nums[s[i]]++;
		}

		for (auto e : nums)
		{
			if (e.second % 2 == 0)
			{
				count += e.second;
			}
			else if (e.second % 2 == 1)
			{
				count += e.second - 1;
				flag++;
			}
		}

		if (flag > 0)
			return count + 1;
		else
			return count;
		return 0;
	}
};