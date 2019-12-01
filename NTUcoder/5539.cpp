#ifndef competitive_programming_H
#define competitive_programming_H
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
#define fix(x) cout<<fixed<<setprecision(x)
#define UNIQUE(c) (c).resize(unique(all(c))-(c).begin())
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
#endif
void solve();
struct ii{
	int x,y;
	ii(){}
	ii(int _x,int _y): x(_x),y(_y) {}
};
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	int vis[n+1][m+1];
	memset(vis,-1,sizeof vis);
	ii p;
	queue<ii> q;
	cin>>p.x>>p.y;
	vis[p.x][p.y]=0;
	q.push(p);
	cin>>p.x>>p.y;
	ii cur;
	int dx[]={-2,-2,-1,-1,1,1,2,2};
	int dy[]={-1,1,-2,2,-2,2,-1,1};
	int nx,ny;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.x==p.x&&cur.y==p.y)
			break;
		fora(k,0,8){
			nx=cur.x+dx[k];
			ny=cur.y+dy[k];
			if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]!=-1)continue;
			vis[nx][ny]=vis[cur.x][cur.y]+1;
			q.push(ii(nx,ny));
		}
	}
	cout<<vis[p.x][p.y];
}