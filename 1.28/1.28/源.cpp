#include<iostream>
#include<stdlib.h>
void Left(char c[], int len, int k)
{
	k = k%len;
	char *p = (char *)malloc((2 * len + 1)*sizeof(char));
	strcpy(p, c);
	strcat(p, c);
	strncpy(c, p + k, len);
	free(p);
}

int main()
{
	char c[] = "ABCDE";
	int k = 2;
	int len = strlen(c);
	printf("×óÐýÇ°£º%s\n", c);
	Left(c, len, k);
	printf("×óÐýºó£º%s\n", c);
	return 0;
}
