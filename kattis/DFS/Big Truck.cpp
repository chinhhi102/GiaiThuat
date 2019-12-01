#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <list>
#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fors(i,a,b) for(int i=a-1;i>=b;i--)
#define men(a) menset(a,0,sizeof(a))
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define c1(a) cin>>a
#define c2(a,b) cin>>a>>b
#define c3(a,b,c) cin>>a>>b>>c
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define M_PI 3.14159265358979323846
#define INF 1000000000000000000
#define fix(x) cout<<fixed<<setprecision(x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
#define MAXC 102
int n,m;
int pick[MAXC];
vector<pi> grap[MAXC];
int item[MAXC];
int dist[MAXC];
void solve();
void sol();
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n;
	fora(i,1,n+1){
		cin>>pick[i];
	}
	cin>>m;
	fora(i,0,m){
		int u,v,d;
		cin>>u>>v>>d;
		grap[u].pb({v,d});
		grap[v].pb({u,d});
	}
	sol();
	if(dist[n]==-1)
		cout<<"impossible";
	else
		cout<<dist[n]<<" "<<item[n]<<endl;
}
void sol(){
	memset(dist,-1,sizeof(dist));
	priority_queue<pi,vector<pi>,greater<pi>> pq;
	dist[1]=0;
	item[1]=pick[1];
	pq.push({0,1});
	while(!pq.empty()){
		int curr_dist=pq.top().ff;
		int node=pq.top().ss;
		pq.pop();
		if(curr_dist!=dist[node])
			continue;
//		cout<<node<<" ";
		for(auto edge:grap[node]){
			int child=edge.ff;
			int new_dist=curr_dist+edge.ss;
			if(dist[child]==-1||(new_dist<dist[child])){
				dist[child]=new_dist;
				item[child]=item[node]+pick[child];
				pq.push({new_dist,child});
			}
			if(dist[child]==new_dist){
				item[child]=max(item[child],item[node]+pick[child]);
			}
		}
	}
}
