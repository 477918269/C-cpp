#include<iostream>
#include<vector>

using namespace std;

class BitSet
{
public:
	BitSet(int bitnum)
		:_bitnum(bitnum)
	{
		_bit.resize((bitnum << 3) + 1, 0);
	}
	void Set(size_t x)
	{
		int index = x / 8;
		int num = x % 8;

		_bit[index] |= (1 << num);
	}

	void Reset(size_t x)
	{
		int index = x / 8;
		int num = x % 8;

		_bit[index] &= (~(1 << num));
	}

	bool Test(size_t x)
	{
		int index = x / 8;
		int num = x % 8;

		return _bit[index] & (1 << num);
	}
private:
	vector<char> _bit;
	size_t _bitnum;
};

int main()
{
	BitSet bs(10000);
	bs.Set(9999);
	bs.Set(999);
	bs.Set(99);
	bs.Set(9);

	cout << bs.Test(9999) << endl;
	cout << bs.Test(999) << endl;
	cout << bs.Test(99) << endl;
	cout << bs.Test(9) << endl;
	cout << bs.Test(10) << endl;



	system("pause");
	return 0;
}