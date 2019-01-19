#include<iostream>

using namespace std;

int a = 1;
static int b = 1;
int main()
{
	static int c = 1;
	int d = 1;

	int num[10] = { 1, 2, 3, 4};
	char num2[] = "abcd";
	char* num3 = "abcd";
	int* ptr = (int*)malloc(sizeof(int)* 4);
	free(ptr);
	return 0;
}