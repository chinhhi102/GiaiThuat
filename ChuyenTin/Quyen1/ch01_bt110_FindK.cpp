#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int a[n + 1] = {}, x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	int jp = 1;
	for(int i = 1; i <= n; i++){
		for(int j = jp; j <= n; j++){
			if(a[j] - a[i - 1] == k){
				cout << i << ' ' << j << endl;
				return 0;
			}
			if(a[j] - a[i - 1] > k){
				jp = j;
				break;
			}
		}
	}
	cout << -1 << endl;
}
/*
5 11
1 3 3 4 5
*/
