#include<iostream>
#include<vector>

using namespace std;

//class BitSet
//{
//public:
//	BitSet(int bitnum)
//		:_bitnum(bitnum)
//	{
//		_bit.resize((bitnum << 3) + 1, 0);
//	}
//	void Set(size_t x)
//	{
//		int index = x / 8;
//		int num = x % 8;
//
//		_bit[index] |= (1 << num);
//	}
//
//	void Reset(size_t x)
//	{
//		int index = x / 8;
//		int num = x % 8;
//
//		_bit[index] &= (~(1 << num));
//	}
//
//	bool Test(size_t x)
//	{
//		int index = x / 8;
//		int num = x % 8;
//
//		return _bit[index] & (1 << num);
//	}
//private:
//	vector<char> _bit;
//	size_t _bitnum;
//};

//struct StrHash1
//{
//	size_t operator()()
//};
class ALA
{
public:
	enum{num = 10};
	int a[num];
};




int main()
{
	ALA a;
	cout << a.num << endl;
	system("pause");
}