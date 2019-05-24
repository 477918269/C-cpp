#include "stdio.h"
#include "stdlib.h"

void fun1(){
	int *data = malloc(sizeof(int)* 4);
	data[0] = 1;
	data[1] = 2;
	data[2] = 3;
	data[3] = 4;
	printf("%d\t%d\n", *data, *(data + 1));
}

void fun2(){
	void *data = malloc(sizeof(int)* 4);
	*(int*)(data + sizeof(int)* 0) = 1;
	*(int*)(data + sizeof(int)* 1) = 2;
	*(int*)(data + sizeof(int)* 2) = 3;
	*(int*)(data + sizeof(int)* 3) = 4;
	printf("%d\t%d\n", *(int*)data, *(int*)(data + sizeof(int)* 3));
}

void fun3(){
	int i;
	void *data = malloc(sizeof(int)* 4);
	int *data2 = malloc(sizeof(int)* 4);
	printf("\n");
	for (i = 0; i < 4; i++) {
		printf("test1:%d\n", data + i);
	}
	printf("\n");
	for (i = 0; i < 4; i++) {
		printf("test2:%d\n", data2 + i);
	}
}

int main(){
	fun1();
	fun2();
	fun3();
	return 0;
}
