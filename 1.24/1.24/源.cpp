#include<string.h>
#include<iostream>
using namespace std;
void main()
{
	char a[20], c[] = "i am teacher!";
	strcpy(a, c);
	cout << a << endl;
}