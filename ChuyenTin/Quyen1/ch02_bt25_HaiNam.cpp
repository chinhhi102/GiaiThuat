#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 102
int a[MAX][MAX];
int F[MAX][MAX];
int n, m;
int demSL(int mask){
	memset(F, 0, sizeof F);
	F[0][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mask & (1 << a[i][j]))
				F[i][j] = F[i - 1][j] + F[i][j - 1];
		}
	}
	return F[n][m];
}

#undef int
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	cout << demSL((1<<4) - 1) - demSL((1<<1) + 1) - demSL((1<<2) + 1) - demSL((1<<3) + 1) << endl;
}
/*
3 4
0 3 -1 2
3 3 3 3
3 1 3 0

3
*/
