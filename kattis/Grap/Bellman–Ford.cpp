#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
#define INF 100000000
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int node,edge;
	cin>>node>>edge;
	vector<vi> grap(node+1,vi(node+1,INF));
	fora(i,0,edge){
		int u,v,t;
		cin>>u>>v>>t;
		grap[u][v]=t;
		grap[v][u]=t;
	}
	int source,target;
	cin>>source>>target;
	vi dis(node+1,INF);
	dis[source]=0;
	fora(i,1,node){
		fora(u,1,node+1){
			fora(v,1,node+1){
				if(grap[u][v]==INF)continue;
				dis[v]=min(dis[v],dis[u]+grap[u][v]);
			}
		}
	}
	cout<<dis[target];
}
/*
5 7
1 2 5
1 3 3
1 4 7
2 4 3
2 5 2
3 4 1
4 5 2
1 5
*/
