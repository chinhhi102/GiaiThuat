#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int W[n + 1], V[n + 1];
	for(int i = 1; i <= n; i++) cin >> W[i] >> V[i];
	int B[n + 1][m + 1] = {};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			B[i][j] = B[i - 1][j];
			if(j >= W[i])
				B[i][j] = max(B[i][j], B[i - 1][j - W[i]] + V[i]);
		}
	}
	cout << B[n][m] << endl;
	int K = m;
	while(n){
		if(B[n][K] != B[n - 1][K]){
			cout << n << ' ';
			K -= W[n];
		}
		n--;
	}
}
/*
5 11
3 3
4 4
5 4
9 10
4 5

12
5 2 1
*/
