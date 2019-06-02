#include <cstdio>

const int maxn = 1010;

int n, ans, cnt;
int val[maxn][maxn];

void dfs(int i, int j){
	if (i == n + 1){
		if (cnt > ans) ans = cnt;
		return;
	}
	cnt += val[i][j];
	dfs(i + 1, j + 1); dfs(i + 1, j);
	cnt -= val[i][j];
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= i; j++) scanf("%d", &val[i][j]);
	dfs(1, 1);
	printf("%d", ans);
}