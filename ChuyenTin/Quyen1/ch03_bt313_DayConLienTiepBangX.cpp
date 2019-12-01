#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n + 1];
	vector<pair<int,int>> p;
	for(int i = 1; i <= n; i++) cin >> a[i];
	p.push_back({0, 0});
	p.push_back({a[1],1});
	for(int i = 2; i <= n; i++) p.push_back({p[i - 1].first + a[i], i});
	sort(p.begin(), p.end());
	int l, r;
	int maxx = -1;
	pair<int,int> cur = p[0];
	for(int i = 1; i < n; i++){
		if(p[i].first == cur.first){
			if(maxx < p[i].second - cur.second){
				maxx = p[i].second - cur.second;
				l = cur.second + 1;
				r = p[i].second;
			}
		}else{
			cur = p[i];
		}
	}
	cout << maxx << endl;
	if(maxx > 0)
	for(int i = l; i <= r; i++) cout << a[i] << ' ';
}
/*
5
2 -1 -1 -1 2
*/
