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
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int g[1003][1003];
bool vis[1003][1003];
int dis[1003][1003];
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int T;
	cin>>T;
	while(T--){
		int n,X,Y;
		cin>>n>>X>>Y;
		if(X==Y){
			cout<<0<<endl;
			continue;
		}
		int sx,sy,ex,ey;
		memset(g,0,sizeof g);
		int m=n*n;
		m++;
		int x=1,y=1;
		int k=0;
		fora(i,1,m){
			g[x][y]=i;
			if(i==X){
				sx=x;
				sy=y;
			}else if(i==Y){
				ex=x;
				ey=y;
			}
			if(x+dx[k]>n||y+dy[k]>n||x+dx[k]<1||y+dy[k]<1||g[x+dx[k]][y+dy[k]])
				k=(k+1)%4;
			x+=dx[k];
			y+=dy[k];			
		}
		memset(vis,0,sizeof vis);
		memset(dis,-1,sizeof dis);
		queue<pair<int,int>> q;
		q.push({sx,sy});
		dis[sx][sy]=0;
		bool f=false;
		while(!q.empty()){
			if(f)break;
			sx=q.front().ff;
			sy=q.front().ss;
			q.pop();
			if(vis[sx][sy])
				continue;
			vis[sx][sy]=1;
			fora(k,0,4){
				if(f)break;
				if(gcd(g[sx][sy],g[sx+dx[k]][sy+dy[k]])==1&&!vis[sx+dx[k]][sy+dy[k]]){
					dis[sx+dx[k]][sy+dy[k]]=dis[sx][sy]+1;
					if(sx+dx[k]==ex&&sy+dy[k]==ey)
						f=true;
					q.push({sx+dx[k],sy+dy[k]});
				}
			}
		}
		if(f)
			cout<<dis[ex][ey];
		else
			cout<<-1;
		cout<<endl;
	}
}
