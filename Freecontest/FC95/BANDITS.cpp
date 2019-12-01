#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int gold[700]={};
vector<int> g[50];
bool vis[50]={};
vector<vector<int>> res;
vector<int> cur;
bool operator < (const vector<int> x,const vector<int> y){
	return x.size()<y.size();
}
void dfs(int p){
	if(p==2){
		res.push_back(cur);
		return;
	}
	if(p!=1)
		cur.push_back(p);
	vis[p]=1;
	for(int i=0;i<g[p].size();i++){
		if(!vis[g[p][i]])
			dfs(g[p][i]);
	}
	vis[p]=0;
	if(p!=1)
		cur.pop_back();
}
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<n;i++)
		cin>>gold[i];
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	sort(res.begin(),res.end());
	int minx=res[0].size(),ans=0;
	for(int i=0;i<res.size();i++){
		if(res[i].size()!=minx)break;
		int total=0;
		bool go[50]={};
		for(int u=0;u<res[i].size();u++)
			total+=gold[res[i][u]-1],go[res[i][u]]=1;
		for(int j=0;j<res.size();j++){
			if(i==j)continue;
			int tot=total;
			for(int u=0;u<res[j].size();u++)
				if(go[res[j][u]])
					tot-=gold[res[j][u]-1];
			ans=max(ans,tot);
		}
	}
	cout<<ans;
	return 0;
}
