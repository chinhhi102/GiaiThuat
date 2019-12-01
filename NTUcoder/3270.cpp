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
string s;
int n,q;
ii st[400000];
int left(int p){ return p<<1;}
int right(int p){ return (p<<1)+1;}
void build(int p,int l,int r){
	if(l==r)
		st[p]=ii(s[l-1]=='(',s[l-1]==')');
	else{
		build(left(p),l,(l+r)/2);
		build(right(p),(l+r)/2+1,r);
		ii p1=st[left(p)],p2=st[right(p)];
		st[p]=ii(max(0,p1.ff-p2.ss)+p2.ff,
				 max(0,p2.ss-p1.ff)+p1.ss);
	}
}
ii query(int l,int r,int u,int v,int id){
	if(l>v||r<u)return ii(0,0);
	if(l>=u&&r<=v)return st[id];
	ii p1=query(l,(l+r)/2,u,v,id*2),p2=query((l+r)/2+1,r,u,v,id*2+1);
	return ii(max(0,p1.ff-p2.ss)+p2.ff,
			max(0,p2.ss-p1.ff)+p1.ss);
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>q;
	cin>>s;
	build(1,1,n);
	int u,v;
	fora(i,0,q){
		cin>>u>>v;
		ii res=query(1,n,u,v,1);
		cout<<((!(res.ff||res.ss))?"YES":"NO")<<endl;
	}
}
