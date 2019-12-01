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
int a[100002];
bool b[100002]={};
bool cmp(int x,int y){return x>y;}
int upper_bound(int a[],int n,ll x){
	int l=0,it;
	int count=n,step;
	while(count>0){
		it=l;
		step=count/2;
		it+=step;
		if(!(x<a[it])){
			l=++it;
			count-=step+1;
		}else
			count=step;
	}
	return l;
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,k;
	cin>>n>>k;
	fora(i,0,n)
		cin>>a[i];
	sort(a,a+n);
	ll x;
	ll sum=0;
	fors(i,n,0){
		if(b[i])continue;
		b[i]=1;
		x=a[i]-k;
		sum+=a[i];
		int l=i;
		while(l>=0){
			l=0;
			int it;
			int count=n,step;
			while(count>0){
				it=l;
				step=count/2;
				it+=step;
				if(!(x<a[it])){
					l=++it;
					count-=step+1;
				}else
					count=step;
			}
			while(b[l]||a[l]>x)l--;
			if(l>=0)
				b[l]=1;
			x=a[l]-k;
		}
	}
	cout<<sum;
}
