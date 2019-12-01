#include<bits/stdc++.h>
using namespace std;
vector<bool> dp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n, x;
	cin >> n;
	vector<int> v;
	int t = 0;
	for (int i = 1; i <= n; i++){
		cin >> x;
		t += x;
		if(x%2 == 0){
			v.push_back(x/2);
			v.push_back(x/2);
		}else v.push_back(x);
	}
	if(n == 1){
		cout << v[0] << endl;
		return 0;
	}
	int d = t/2 + t%2;
	n = v.size();
	dp.resize(d + 1);
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		x = v[i];
		for(int j = d; j >= x; j--){
			if(dp[j - x])
				dp[j] = 1;
		}
	}
	int res = 1e9;
	for(int i = 1; i <= d; i++){
		if(dp[i])
			res = min(res, abs(i - d));
	}
	cout << d + res << endl;
}
