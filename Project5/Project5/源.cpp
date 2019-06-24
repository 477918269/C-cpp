#include<iostream>

using namespace std;

//class Year
//{
//public:
//	Year(int year, int month, int day = 100)
//	{
//
//	}
//private:
//
//	int year;
//	int month;
//	int day;
//};

struct A
{
	unsigned a : 19;
	unsigned b : 11;
	unsigned c : 4;
	unsigned d : 29;
	char index;
};


int main()
{
	//cout << sizeof(A) << endl;
	//char a[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0}, *p; int i;
	//i = 8;
	//p = a + i;
	//printf("%s\n", p - 3);

	int a[][3] = { { 1, 2 }, { 4 } };
	for (auto e : a)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}