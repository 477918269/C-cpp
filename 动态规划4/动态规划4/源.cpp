#include<stdio.h>
#define x 9999;
#define max 9999;
int dist[10];

void f(int a[][11]){
	int i, j, k;
	dist[0] = 0;
	for (i = 1; i<10; i++){
		k = max;
		for (j = 0; j<i; j++){
			if (a[j][i] != 0){
				if (dist[j] + a[j][i]<k){
					k = dist[j] + a[j][i];
				}
				dist[i] = k;

			}
		}
	}
}

int main(){
	int i;
	int a[][11] = { { 0, 4, 2, 3, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 10, 9, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 6, 7, 10, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 3, 8, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 4, 8, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 9, 6, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 5, 4, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 8 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	f(a);
	printf("%d\n", dist[9]);
}
