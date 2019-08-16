#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int dp[100][100];

int Min(int a, int b){
	if (a<b){
		return a;
	}
	else{
		return b;
	}
}

int getMin(int m, int n){
	int min;

	dp[0][0] = a[0][0];
	for (int i = 1; i<m; i++){
		dp[i][0] = a[i][0] + dp[i - 1][0];
	}
	for (int i = 1; i<n; i++){
		dp[0][i] = a[0][i] + dp[0][i - 1];
	}

	for (int i = 1; i<m; i++){
		for (int j = 1; j<n; j++){
			min = Min(dp[i - 1][j], dp[i][j - 1]);
			dp[i][j] = min + a[i][j];
		}
	}

	return dp[m - 1][n - 1];
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);

	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d\n", getMin(m, n));

	return 0;
}
