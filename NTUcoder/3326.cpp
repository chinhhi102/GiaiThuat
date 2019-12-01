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
ll a[1000005]={};
ll res;
ll st[4*1000005]={};
ll pt[4*1000005]={};
int left(int p){return p<<1;}
int right(int p){return (p<<1)+1;}
void upt(int p,int l,int r){
	if(l==r)
		st[p]=a[l];
	else{
		upt(left(p),l,(l+r)/2);
		upt(right(p),(l+r)/2+1,r);
		st[p]=max(st[left(p)],st[right(p)]);
	}
}
void rmq(int p,int l,int r,int u,int v){
	if(pt[p]){
		st[p]=pt[p];
		pt[left(p)]=pt[p];
		pt[right(p)]=pt[p];
		pt[p]=0;
	}
	if(l>v||r<u)return;
	if(l>=u&&r<=v){
		res=max(res,st[p]);
		return;
	}
	rmq(left(p),l,(l+r)/2,u,v);
	rmq(right(p),(l+r)/2+1,r,u,v);
}
void upt(int p,int l,int r,int u,int v,int x){
	if(pt[p]){
		st[p]=pt[p];
		pt[left(p)]=pt[p];
		pt[right(p)]=pt[p];
		pt[p]=0;
	}
	if(l>v||r<u)return;
	if(l>=u&&r<=v){
		if(l==r){
			st[p]=x;
			return;
		}else{
			pt[p]=x;
			st[p]=x;
			return;
		}
	}
	upt(left(p),l,(l+r)/2,u,v,x);
	upt(right(p),(l+r)/2+1,r,u,v,x);
	st[p]=max(st[left(p)],st[right(p)]);
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,q;
	cin>>n>>q;
	fora(i,1,n+1)
		cin>>a[i];
	upt(1,1,n);
	int u,v;
	fora(i,0,q){
		cin>>u>>v;
		res=0;
		rmq(1,1,n,u,u+v-1);
		cout<<res+1<<endl;
		upt(1,1,n,u,u+v-1,res+1);
	}
}
