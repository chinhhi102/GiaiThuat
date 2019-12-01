#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
int a[MAXN];
int main(){
	int n;
	cin >> n;
	int x;
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> x;
		i[a] = (i - 1)[a] + x;
	}
//	for(int i = 1; i <= n; i++)
//		cout << a[i] << ' ';
	int q, l, r;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> l >> r;
		cout << r[a] - (l - 1)[a] << endl;
	}
}
/*
5
1 3 5 7 9
3
1 3
2 4
3 5
*/
