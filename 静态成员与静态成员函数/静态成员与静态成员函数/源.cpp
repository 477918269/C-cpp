#include<iostream>

using namespace std;

class ALA
{
public:
	ALA(int a, int b, int c);
	void GetSum();

private:
	int a, b, c;
	static int d;
};

int ALA::d = 0;


int main()
{

	system("pause");
}