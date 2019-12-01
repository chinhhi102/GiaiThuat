#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000010
long long a[MAXN], t[MAXN], g[MAXN];
int main(){
	int n;
	cin >> n;
	long long res = 0;
	t[0] = g[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		t[i] = (a[i] > a[i-1] ? t[i - 1] + 1: 1);
		g[i] = (a[i] < a[i-1] ? g[i - 1] + 1: 1);
		res += t[i] + g[i] - 1;
	}
	cout << res;
}
