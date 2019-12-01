#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	sort(x, x + n);
	sort(y, y + n);
	cout << x[n / 2] << ' ' << y[n / 2];
}
/*
4
0 0
2 2
0 2
2 0

3
0 2
2 0
0 0
*/
