#include <iostream>
using namespace std;

//#define SQR(A) A*A
//void main()
//{
//	int x=6,y=3,z=2;
//	x/=SQR(y+z)/SQR(y+z);
//	cout<< x << endl;
//}



//void func(const int& v1, const int& v2)
//{
//	cout << v1 << ' ';
//	std::cout << v2 << ' ';
//}
//
//int main(int argc, char* argv[])
//{
//	//int i = 0;
//	//func(i++, i);
//	int i = 0;
//	for (int i = 0; i < 10; )
//
//
//	system("pause");
//	return 0;
//}

class Base 
{
public:
	int Bar(char x){ return (int)(x); }
	virtual int Bar(int x)     { return (2 * x); }
};
class Derived : public Base
{
public:
	int Bar(char x)     { return (int)(-x); }
	int Bar(int x)     { return (x / 2); };
};
int main(void)
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));
	printf("%d,", pObj->Bar(100));
}
