#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n + 1][n + 1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
	int res = 0;
	for(int i = k; i <= n; i++)
		for(int j = k; j <= n; j++)
			res = max(res, dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k]);
	cout << res;
}
