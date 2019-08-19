
#include<stdio.h>
#include<string.h>
int dp[100][100];

int Max(int a, int b, int c){
	int max = a;
	if (b>max){
		max = b;
	}
	if (c>max){
		max = c;
	}
	return max;
}

int getMax(char s1[], char s2[], int m){
	int i, j;
	for (i = 0; i<m; i++){
		if (s1[0] == s2[i]){
			dp[0][i] = 1;
			for (j = i + 1; j<m; j++){
				dp[0][j] = 1;
			}
			break;
		}
	}
	for (int i = 0; i<m; i++){
		if (s1[i] == s2[0]){
			dp[i][0] = 1;
			for (j = i + 1; j<m; j++){
				dp[j][0] = 1;
			}
			break;
		}
	}

	for (i = 1; i<m; i++){
		for (j = 1; j<m; j++){
			if (s1[i] == s2[j]){
				dp[i][j] = Max(dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1]);
			}
			else{
				dp[i][j] = dp[i - 1][j] >= dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
		}
	}

	return m - dp[m - 1][m - 1];
}

int main(){
	int m, n;
	char s1[100];
	char s2[100];
	gets(s1);
	m = strlen(s1);
	for (n = 0; n<m; n++){
		s2[n] = s1[m - n - 1];
	}

	printf("%d\n", getMax(s1, s2, m));

	return 0;
}
