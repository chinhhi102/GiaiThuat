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

#define inf 0x3f3f3f3f

void solve();
int n,idx;
map<string,int> m;	// luu vi tri cua tram
map<int,string> station;	//luu gia tri cua tram
vector<string> v;
string s;
int vis[5000],dis[5000],pre[5000];	//vis la bien xem da xet chua, dis la khoang cach gan nhat giua nut dang xet, pre la vi tri tiep theo dang luu
int G[5000][5000];	//G la ma tran ke lien ket cac so
void init(){
	m.clear();
	station.clear();
	fora(i,0,5000)
		fora(j,0,5000)
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=inf;
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	idx=0;
	cin.ignore();
	fora(i,0,n){
		getline(cin,s);
		v.clear();
		string temp;
		istringstream iss(s);
		while(iss>>temp){
			v.pb(temp);
		}
		fora(i,0,v.size()){
			if(m.count(v[i])==0){
				m[v[i]]=idx;
				station[idx]=v[i];
				idx++;
			}
		}
		fora(i,1,v.size()){
			G[m[v[0]]][m[v[i]]]=G[m[v[i]]][m[v[0]]]=1;
		}
	}
}
void dij(int st){
	dis[st]=0;
	vis[st]=1;
	fora(i,0,idx){
		int minx=inf,next=st;
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
			if(!vis[j]){
				if(dis[j]>dis[next]+G[next][j]){
					dis[j]=dis[next]+G[next][j];
					pre[j]=next;
				}
			}
		}
	}
}
void path(int ed){
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
	init();
	string st,se;
	cin>>st>>se;
	if(m.count(st)==0||m.count(se)==0){
		cout<<"no route found"<<endl;
		return;
	}
//	fora(i,0,idx){
//		fora(j,0,idx){
//			cout<<G[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	dij(m[st]);
	if(dis[m[se]]==inf)
		cout<<"no route found"<<endl;
	else{
		path(m[se]);
		cout<<station[m[se]];
	}
}
