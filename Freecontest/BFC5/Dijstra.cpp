#include<bits/stdc++.h>
using namespace std;
#define oo 1000000
int main(){
	ifstream f1;
	f1.open("inp.txt");
//	freopen("inp.txt","r",stdin);
	vector<pair<int,int>> V[26];
	int dis[27];
	int n,m;
	f1>>n>>m;
	for(int i=0;i<m;i++){
		char a,b;
		int w;
		f1>>a>>b>>w;
		V[a-'A'].push_back({w,(b-'A')});
		V[b-'A'].push_back({w,(a-'A')});
	}
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<26;i++)
		dis[i]=oo;
	char a;
	cin>>a;
	dis[a-'A']=0;
	pq.push({0,{a-'A'}});
	int path[27]={};
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		for(int i=0;i<V[u].size();i++){
			if(dis[V[u][i].second]>dis[u]+V[u][i].first){
				dis[V[u][i].second]=dis[u]+V[u][i].first;
				pq.push({-dis[V[u][i].first],V[u][i].second});
				path[V[u][i].second]=u;
			}
		}
	}
	for(int i=0;i<=n;i++){
		if(i!=(a-'A')){
			if(dis[i]==oo){
				continue;
			}
			cout<<dis[i]<<endl;
			cout<<char(i+'A');
			int pre=i;
			while(path[pre]){
				cout<<" <- "<<char(path[pre]+'A');
				pre=path[pre];
			}
			cout<<" <- "<<a<<endl<<"Break!"<<endl<<endl;
		}
	}
}
