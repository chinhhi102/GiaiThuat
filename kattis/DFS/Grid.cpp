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
#define INF 100000000
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
typedef queue<pair<int,int>> q;
typedef vector<vector<int>> vvc;
void solve();
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void bfs(vvc& v,vvc& dist,q& oc){
	while(!oc.empty()){
		int currx=oc.front().ff;
		int curry=oc.front().ss;
		oc.pop();
		fora(i,0,4){
			int nextx=currx+dx[i]*v[currx][curry];
			int nexty=curry+dy[i]*v[currx][curry];
			if(nextx<n&&nextx>=0&&nexty<m&&nexty>=0){
				if(dist[currx][curry]+1<dist[nextx][nexty]){
					dist[nextx][nexty]=dist[currx][curry]+1;
					oc.push({nextx,nexty});
				}
			}
		}
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>m;
	vvc grid(n,vi(m));
	vvc dist(n,vi(m,INF));
	fora(i,0,n)
		fora(j,0,m){
			char a;
			cin>>a;
			grid[i][j]=a-'0';
		}
	dist[0][0] = 0;
	q curr;
	curr.push({0,0});
	int time=0;
	bool work;
	while(!curr.empty()){
		bfs(grid,dist,curr);
	}
	int d=dist[n-1][m-1];
	if(d==INF)
		cout<<-1<<endl;
	else
		cout<<d<<endl;
}
