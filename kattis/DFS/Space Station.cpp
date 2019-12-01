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

void solve();
void solve2();
int main(){
	io;
//	solve();
	solve2();
	return 0;
}

void solve(){
	int cases;
	cin>>cases;
	cases++;
	fora(id,1,cases){
		int n,m;
		cin>>n>>m;
		vector<set<int>> grap(n+1);
		vector<int> dis(n+1,0);
		vector<pair<int,int>> adj(n+1,pi ({0,0}));
		fora(i,0,m){
			int u,v;
			cin>>u>>v;
			grap[u].insert(v);
			grap[v].insert(u);
//			adj[u].ff++;
//			adj[u].ss=u;
//			adj[v].ff++;
//			adj[v].ss=v;
//			dis[u]++;
//			dis[v]++;
		}
		int remove=0;
//		sort(adj.begin(),adj.end());
		fora(i,1,n+1){
			int curr=adj[i].ss;
			bool leave=true;
			if(dis[curr]<2)continue;
			for(auto node:grap[curr]){
				for(auto next_node:grap[curr]){
//					cout<<node<<" "<<next_node<<endl;
					if(node==next_node)continue;
					if(grap[node].count(next_node)==0)
						leave=false;
				}
			}
//			cout<<leave<<endl;
			if(leave){
				remove++;
				for(auto member:grap[curr]){
					dis[member]--;
				}
			}
			
		}
		cout<<"Case #"<<id<<endl<<n-remove<<endl;
	}
}
void solve2(){
	int cases;
	cin>>cases;
	cases++;
	fora(id,1,cases){
		int n,m;
		cin>>n>>m;
		map<pair<int,int>,bool> inv;
		vector<unordered_set<int>> grap(n+1);
		vector<bool> valid(n+1,true);
		fora(i,0,m){
			int u,v;
			cin>>u>>v;
			grap[u].insert(v);
			grap[v].insert(u);
			if(u<v)
				inv[{u,v}]=true;
			else
				inv[{v,u}]=true;
		}
		fora(i,1,n){
			fora(j,i+1,n+1){
				if(!inv[{i,j}]){
					fora(k,1,n+1){
						if((inv[{i,k}]||inv[{k,i}])&&(inv[{j,k}]||inv[{k,j}]))
							valid[k]=false;
					}
				}
			}
		}
		int remove=0;
		fora(i,1,n+1)
			if(valid[i]){
				if(grap[i].size()>1){
					remove++;
					for(auto member:grap[i]){
						grap[member].erase(i);
					}
				}
			}
		cout<<"Case #"<<id<<endl<<n-remove<<endl;
	}
}
/*
1
13 30
1 2
1 3
1 5
2 5
5 4
4 3
3 2
2 6
2 7
5 8
5 9
4 10
4 11
3 12
3 5
1 2
3 1
2 3
4 4
1 2
2 3
3 4
1 4
5 6
1 2
2 3
1 4
2 4
2 5
3 5
*/
