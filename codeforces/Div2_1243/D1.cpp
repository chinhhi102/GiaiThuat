#include<bits/stdc++.h>
using namespace std;
map<int,bool> g[100010];
set<int> s, ns;
void DFS(int x){
	vector<int> v;
	ns.clear();
	for(auto u:s){
		if(!g[x][u]) v.push_back(u);
		else ns.insert(u);
	}
	s = ns;
	for(auto u:v) DFS(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = true;
	}
	for(int i = 1; i <= n; i++) s.insert(i);
	int res = 0;
	while(s.size()){
		res++;
		int u = *s.begin();
		s.erase(u);
		DFS(u);
	}
	cout << res - 1 << endl;
}
