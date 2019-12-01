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
bool founded=false;
int res;
int n,m,p,k;
vi cl;
string s;
map<char,int> dy={{'U',-1},{'D',1},{'L',0},{'R',0}};
map<char,int> dx={{'U',0},{'D',0},{'L',-1},{'R',1}};
void kt(vector<vb>& v){
	int sx=1,sy=1,idx=0;
	fora(i,0,k){
		if(cl[idx]==i){
			idx++;
			continue;
		}
		if(!(v[sy+dy[s[i]]][sx+dx[s[i]]])){
			sx+=dx[s[i]];
			sy+=dy[s[i]];
		}
//		cout<<sx<<' '<<sy<<endl;
	}
	founded=(sx==m&&sy==n);
//	cout<<endl;
}
void backtracking(vector<vb>& v,int x,int d){
	cl.pb(x);
	if(cl.size()==d){
		cl.push_back(-1);
		kt(v);
		cl.pop_back();
		cl.pop_back();
		return;
	}
	fora(i,x+1,k){
		backtracking(v,i,d);
		if(founded)return;
	}
	cl.pop_back();
}
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	cin>>n>>m>>p>>k;
	vector<vb> v(n+2,vb(m+2,0));
	fora(i,0,n+2)
		v[i][0]=v[i][m+1]=1;
	fora(i,0,m+2)
		v[0][i]=v[n+1][i]=1;
	cin>>s;
	fora(i,0,p){
		int x,y;
		cin>>x>>y;
		v[x][y]=1;
//		cout<<x<<' '<<y<<endl;
	}
	fora(i,0,k+1){
		res=i;
		cl.clear();
		fora(j,0,k){
			backtracking(v,j,i);
			if(founded)break;
		}
		if(founded)break;
	}
	if(founded)
		cout<<res<<endl;
	else
		cout<<-1<<endl;
}
/*
5 5 2 12
RDDDDRRRRRUD
2 2
5 3
*/
