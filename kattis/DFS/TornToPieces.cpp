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
#define inf	0x3f3f3f3f
void solve();
int n,idx;
map<string,int> m;
map<int,string> station;
vector<string> v;
int dp[1000][1000];
int vis[1000],pre[1000],dis[1000];
void path(int ed){
//	cout<<pre[ed]<<endl;
	if(pre[ed]!=-1){
		path(pre[ed]);
		cout<<station[pre[ed]]<<' ';
	}
}
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	cin>>n;
	cin.ignore();
	idx=0;
	m.clear();
	station.clear();
	fora(i,0,1000)
		fora(j,0,1000)
			dp[i][j]=(i==j)?0:inf;
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	memset(dis,inf,sizeof(dis));
	fora(cas,0,n){
		string line;
		getline(cin,line);
		v.clear();
		istringstream iss(line);
		string temp;
		while(iss>>temp)
			v.pb(temp);		
		fora(i,0,v.size()){
			if(m.count(v[i])==0){
				m[v[i]]=idx;
				station[idx]=v[i];
				idx++;
			}
		}
		fora(i,1,v.size())
			dp[m[v[0]]][m[v[i]]]=dp[m[v[i]]][m[v[0]]]=1;
	}
	string st,se;
	cin>>st>>se;
	if(m.count(st)==0||m.count(se)==0){
		cout<<"no route found"<<endl;
		return;
	}
//	fora(i,0,idx){
//		fora(j,0,idx){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	vis[m[st]]=1;
	dis[m[st]]=0;
	fora(i,0,idx){
		int minx=inf,next=m[st];
		fora(j,0,idx){
//			cout<<dis[j]<<' ';
			if(!vis[j]&&minx>dis[j]){
				minx=dis[j];
				next=j;
			}
		}
//		cout<<endl;
		vis[next]=1;
		fora(j,0,idx){
			if(!vis[j]&&dis[j]>(dis[next]+dp[next][j])){	
				dis[j]=dis[next]+dp[next][j];
				pre[j]=next;
			}
		}
	}
	if(dis[m[se]]==inf)
		cout<<"no route found"<<endl;
	else{
		path(m[se]);
		cout<<station[m[se]];
	}
}
