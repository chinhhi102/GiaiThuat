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
int res=0;
bool is;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
int dem;
void DFS(vector<vector<int>>& v,vector<vector<bool>>& vis,int x,int y){
	vis[x][y]=true;
	dem++;
	fora(i,0,4){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(v[x][y]>v[nx][ny])
			is=false;
		if(!vis[nx][ny]&&v[nx][ny]==v[x][y]){
			DFS(v,vis,nx,ny);
		}
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	vector<vector<int>> v;
	vector<vector<bool>> vis;
	int n,m;
	cin>>m>>n;
	v.resize(n+2,vector<int> (m+2,1000));
	vis.resize(n+2,vector<bool> (m+2,false));
	fora(i,1,n+1)
		fora(j,1,m+1)
			cin>>v[i][j];
	fora(i,1,n+1){
		fora(j,1,m+1){
			if(vis[i][j])continue;
			dem=0;
			is=true;
			DFS(v,vis,i,j);
			if(is){
				res+=dem;
			}
		}
	}
	cout<<res<<endl;
}
