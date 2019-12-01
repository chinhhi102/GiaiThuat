#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
map<int,int>g[200005];
set<int>s,ns;
void dfs(int x){
	vector<int> v;
	v.clear();
	ns.clear();
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
		if(!g[x][*it])
			v.push_back(*it);
		else
			ns.insert(*it);
	s=ns;
	for(int i:v)
		dfs(i);
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = 1;
	}
	for(int i = 1; i <= n; i++){
		s.insert(i);
	}
	while(s.size()){
		cnt++;
		int t=*s.begin();
		s.erase(t);
		dfs(t);
	}
	cout << cnt - 1 << endl;
}
