#include<iostream>

//普通命名空间

namespace N1//以N1为命名空间名称
{
	int a = 10;
}

namespace N2//设计嵌套空间
{
	int a = 1;
	int b = 2;
	namespace N3
	{
		int c = 3;
		int b = 4;
	}
}

using namespace N1;//2.使用using namespace 命名空间名称引入， 要加;

using N1::a;

using namespace std; //C++的标准空间

int main()
{
	//printf("%d", N1 :: a);//第一种方法 加命名空间名称及作用域限定符::
	//printf("%d",a);
	//printf("%d", N2::N3::c);//调用嵌套空间的时候，要先调用被嵌套空间的名称
	//C++的标准输出
	//1.使用cout和cin时，必须包含< iostream >头文件以及std标准命名空间。
	//2.使用C++输入输出更方便，不需增加数据格式控制，比如：整形--%d，字符--%c

	int a;
	int b;
	int c;
	int d;
	//cin >> a;
	cin >> b >> c>>d;//输入的前后顺序
	//cout << a  << endl;
	cout << b << d << " "<< c << endl;//排序bcd的顺序
	system("pause");
	return 0;
}

