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
//#include <tuple>
#include <ctype.h>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <time.h>
//#include <unordered_map>
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

int total=2;
void solve();
void dfs(vector<vi>& adj,vi& up,vi& down,int parent,int start){
	for(int next=0;next<adj[start].size();next++){
		if(up[adj[start][next]]==-1){
			up[adj[start][next]]=total;
			down[adj[start][next]]=total;
			total++;
			dfs(adj,up,down,start,adj[start][next]);
			down[start]=min(down[start],down[adj[start][next]]);
		}else{
			if(adj[start][next]!=parent){
				down[start]=min(down[start],down[adj[start][next]]);
			}
		}
	}
}
bool findbridge(vector<vi>& adj){
	int n=adj.size();
	vi up(n,-1);
	vi down(n);
	up[0]=1;
	down[0]=1;
	dfs(adj,up,down,0,0);
	fora(i,1,n){
		if(up[i]==down[i])
			return true;
	}
	return false;
}
int find(vi& d,int a){
	if(d[a]==-1)
		return a;
	d[a]=find(d,d[a]);
	return d[a];
}
void join(vi& d,int a,int b){
	a=find(d,a);
	b=find(d,b);
	if(a==b)
		return;
	d[a]=b;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	while(cin>>n&&cin>>m&&n!=0&&m!=0){
		vector<vi> adj(n);
		vi d(n,-1);
		fora(i,0,m){
			int n1,n2;
			cin>>n1>>n2;
			adj[n1].pb(n2);
			adj[n2].pb(n1);
			join(d,n1,n2);
		}
		bool conect=true;
		fora(i,1,n){
			if(find(d,i)!=find(d,0))
				conect=false;
		}
		if(!conect||findbridge(adj))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
