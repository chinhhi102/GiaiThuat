#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int a[n + 1], b[m + 1];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int L[n + 1][m + 1];
	memset(L, 0, sizeof L);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			L[i][j] = max(max(L[i][j - 1], L[i - 1][j]), L[i - 1][j - 1] + (a[i] == b[j]));
	cout << L[n][m] << endl;
}
/*
5 6
1 3 5 7 9
2 3 5 7 8 9
*/
