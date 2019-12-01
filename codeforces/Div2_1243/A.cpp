#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		int res = 0;
		for(int i = 0; i < n; i++){
			res = max(res, min(a[i], n - i));
		}
		cout << res << endl;
	}
}
