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

int n,m,dem=0;
int dx[]={0,1};
int dy[]={1,0};
int a[22][22];
vector<pair<int,int>> path;
bool cate[4]={};
void solve();
void sol(int x,int y){
	path.pb({x,y});
	if(x==n&&y==m){
		if(dem<2)return;
		fora(i,0,path.size())
			cout<<path[i].ff<<" "<<path[i].ss<<endl;
		exit(0);
	}
	fora(i,0,2){
		bool f=0;
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>n||ny>m)continue;
		if(a[nx][ny]<0)continue;
		if(!cate[a[nx][ny]]&&a[nx][ny]!=0){
			cate[a[nx][ny]]=1;
			dem++;
			f=1;
		}
		sol(nx,ny);
		path.pop_back();
		if(f){
			cate[a[nx][ny]]=0;
			dem--;
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
	fora(i,1,n+1)
		fora(j,1,m+1)
			cin>>a[i][j];
	sol(1,1);
	cout<<-1;
}
