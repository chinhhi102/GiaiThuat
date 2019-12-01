#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	pair<int,int> x[n];
	for(int i = 0; i < n; i++) cin >> x[i].first >> x[i].second, x[i].second -= x[i].first;
	sort(x, x + n);
	int l = x[0].second;
	int p = x[0].first + x[0].second;
	for(int i = 1; i < n; i++){
		if(p < x[i].first){
			l += x[i].second;
			p = x[i].first + x[i].second;
		}else if(p < x[i].first + x[i].second){
			l += x[i].first + x[i].second - p;
			p = x[i].first + x[i].second;
		}
	}
	cout << l << endl;
}
/*
3
5 10
0 6
-100 10
*/
