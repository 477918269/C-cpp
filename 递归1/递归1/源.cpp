#include<iostream>

using namespace std;

class Test
{ 
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)    { a = temp1;        b = temp2; }
	int getA()     { return a; }
	retunr
	int getB()     { return b; }
};
int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt+0) = 100;
	*(pInt+1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	cout << sizeof(Test) << endl;
	system("pause");
	return 0;
	int mian()
		funck 1 = 0;
	//虚表占据了4个字节在类中

} 