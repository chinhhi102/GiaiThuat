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
#define forcin(i,a,b,c)	for(int i=a;i<b;cin>>c[i++])
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
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef map<int,int> mi;
typedef map<long,long> mll;
#endif
void solve();

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,t,p;
	cin>>n>>t>>p;
	pair<int,int> a[n];
	pair<int,int> dk1[n];
	pair<int,int> dk2[n];
	bool vis[n];
	int x,y,u,v;
	fora(i,0,n){
		cin>>x>>y>>u>>v;
		dk1[i]={x,i};
		dk2[i]={y,i};
		a[i]={u,v};
	}
	sort(dk1,dk1+n);
	sort(dk2,dk2+n);
	memset(vis,0,sizeof vis);
	int res=0;
	bool f=1;
	while(f){
		f=0;
		fora(i,0,n){
			fora(j,0,n){
				if(dk1[i].ss==dk2[j].ss){
					int id=dk1[i].ss;
					if(vis[id])continue;
					if(t>=dk1[i].ff&&p>=dk2[j].ff){
						f=1;
						vis[id]=1;
						t+=a[id].ff;
						p+=a[id].ss;
						res++;
					}
				}
			}
		}
	}
	cout<<res;
}
