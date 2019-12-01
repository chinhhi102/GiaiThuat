#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	int jp = n - 1;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = jp; j > i; j--){
			if(a[i] + a[j] == 0){
				cout << i << ' ' << j << endl;
				return 0;
			}
			if(a[j] < -a[i]){
				jp = j;
				break;
			}
		}
	cout << -1;
}
/*
5
-3 -2 0 2 4
*/
