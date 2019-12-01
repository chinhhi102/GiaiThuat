#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	int jp = n - 1;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++){
			for(int k = jp; k > j; k--){
				if(a[i] + a[j] + a[k] == 0){
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
				if(a[k] < -(a[j] + a[i])){
					jp = k;
					break;
				}
			}
		}
	cout << -1;
}
/*
6
-3 -2 0 2 4 9
*/
