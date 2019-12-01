#include "D:\\baiTapLapTrinh\competitive_programming.h"
void solve();
const int MAXN=1005;
int n,m,a,b,k,g;
vector<pi> graph[MAXN];
map<pi,pi> george;
int r[MAXN],times[MAXN];
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>m;
	cin>>a>>b>>k>>g;
	fora(i,0,g)
		cin>>r[i];
	fora(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].pb({v,w});
		graph[v].pb({u,w});
	}
	times[0]=0;
	fora(i,0,g-1){
		fora(j,0,graph[r[i]].size()){
			if(graph[r[i]][j].ff==r[i+1]){
				times[i+1]=times[i]+graph[r[i]][j].ss;
				george[{r[i],r[i+1]}]=george[{r[i+1],r[i]}]={times[i],times[i+1]};
				break;
			}
		}
	}
//	for(map<pi,pi>::iterator it=george.begin();it!=george.end();it++)
//		cout<<it->ff.ff<<' '<<it->ff.ss<<" : "<<it->ss.ff<<' '<<it->ss.ss<<endl;
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	vi dist(n+1,-1);
	dist[a]=k;
	pq.push({dist[a],a});
	while(!pq.empty()){
		int curr,u;
		tie(curr,u)=pq.top();
		pq.pop();
		if(curr!=dist[u])
			continue;
		fora(i,0,graph[u].size()){
			int v,w;
			tie(v,w)=graph[u][i];
			int time=curr+w;
			if(george.find({u,v})!=george.end()){
				if(curr>=george[{u,v}].ff)
					time=max(time,george[{u,v}].ss+w);
			}
			if(dist[v]==-1||time<dist[v]){
				dist[v]=time;
				pq.push({dist[v],v});
			}
		}
	}
	cout<<dist[b]-k<<endl;
}
