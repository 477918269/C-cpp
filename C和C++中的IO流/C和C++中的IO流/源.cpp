#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 10000;
	FILE* op = fopen("test.txt", "wb");
	fwrite(&a, sizeof(a), 1, op);
	fclose(op);
	op = NULL;
	system("pause");
	return 0;
}


//int main()
//{
//	FILE *fp;
//	char str[] = "This is runoob.com";
//
//	fp = fopen("file.txt", "w");
//	fwrite(str, sizeof(str), 1, fp);
//
//	fclose(fp);
//
//	return(0);
//}

//int main()
//{
//	FILE *fp;
//	int c;
//
//	fp = fopen("test.txt", "r");
//	while (1)
//	{
//		c = fgetc(fp);
//		if (feof(fp))
//		{
//			break;
//		}
//		printf("%c", c);
//	}
//	fclose(fp);
//	system("pause");
//	return(0);
//}

//int main()
//{
//	FILE * pFile;
//	pFile = fopen("file.txt", "w");
//	if (pFile != NULL)
//	{
//		fputs("fopen example", pFile);
//		fclose(pFile);
//	}
//	system("pause");
//	return 0;
//}