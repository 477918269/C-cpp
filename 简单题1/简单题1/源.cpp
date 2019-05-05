class Solution {
public:
	vector<string> letterCombinations(string digits)
	{
		map<string, string> m{
			{ "2", "abc" },
			{ "3", "def" },
			{ "4", "ghi" },
			{ "5", "jkl" },
			{ "6", "mno" },
			{ "7", "pqrs" },
			{ "8", "tuv" },
			{ "9", "wxyz" }
	};
		vector<string> v;

		for (int i = 0; i < digits.size(); i++)
		{
			v[i] += m[digits[i]];
		}

		vector<stirng> v1;

		for (int k = 0; k < v[0].size(); k++)
		{
			for (int i = 1; i < v.size(); i++)
			{
				string s;
				for (int j = 0; j < v[i].size(); j++)
				{
					s += v[0][k];
					s += v[][]
				}
			}
		}
	}
};