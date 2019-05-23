//#include<iostream>
//
//using namespace std;
//int func() 
//{ 
//	int i, j, k = 0;   
//	for (i = 0, j = -1; i++, j++; j == 0)   
//	{ 
//		k++; 
//	} 
//	return k; 
//} 
//int main() 
//{ 
//	cout << (func());
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{ 
//			itor = array.erase(itor);
//		}
//	} 
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " "; 
//	}  
//	system("pause");
//	return 0;
//}

#include<iostream>

using namespace std;

struct Test 
{ 
	char *pcName;
	short sDate;
	char p1[2];

}*p;
int main()
{
	//int a[] = { 1, 2, 3, 4 };
	//printf("%d\n", a);
	//printf("%d\n", a + 0);
	//printf("%d\n", *a);
	//printf("%d\n", a + 1);
	//printf("%d\n", a[1]);
	//printf("%d\n", &a);
	//printf("%d\n", *&a);
	//printf("%d\n", &a + 1);
	//printf("%d\n", &a[0]);
	//printf("%d\n", &a[0] + 1);

	//int a[5] = { 1, 2, 3, 4, 5 };
	//int *ptr = (int *)(&a + 1);
	//printf("%d,%d", *(a + 1), *(ptr - 1));
	//char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, *p; int i;
	//i = 8;
	//p = a + i;
	//printf("%s\n", p - 3);
	int a[] = { 1, 2, 3, 4 };
	int *b = a;
	*b += 2;
	*(b + 2) = 2;
	b++;
	printf("%d, %d\n", *b, *(b + 2));

	system("pause");
	return 0;
}