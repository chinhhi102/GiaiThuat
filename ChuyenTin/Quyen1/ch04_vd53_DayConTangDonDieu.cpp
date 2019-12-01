#include<bits/stdc++.h>
#define MAXN 1010
#define INF 1e9
int a[MAXN], L[MAXN] = {}, T[MAXN];
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	L[n + 1] = 1;
	a[0] = 0;
	a[n + 1] = INF;
	for(int i = n; i >= 0; i--){
		int jmax = i;
		for(int j = i + 1; j <= n + 1; j++){
			if(a[i] < a[j] && L[jmax] < L[j])
				jmax = j;
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
	int i = T[0];
	cout << L[0] - 2 << endl;
	while(i != (n + 1)){
		cout << a[i] << ' ';
		i = T[i];
	}
}
/*
10
1 5 3 4 9 10 5 6 7 8
*/
