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
#define debug freopen("D:\\baiTapLapTrinh\\UVa\\out.txt","w",stdout);
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
#define base 1000000007
void solve();
void solve2();
int b[10000010];
ll f[10000010]={0},g[10000010]={1};
int n,res=1,pos=0;
string s;
int main(){
	io;
//	solve();
	solve2();
	return 0;
}

void solve(){
	string s;
	cin>>s;
	int n=(int)s.size();
	int i=0,j=-1;b[0]=-1;
	pair<int,int> res={0,0};
	while(i<n){
		while(j>=0&&s[i]!=s[j])
			j=b[j];
		i++;j++;
		b[i]=j;
		if(j>res.ss){
			res.ss=j;
			res.ff=i-j;
		}
	}
	cout<<res.ss<<' '<<res.ff+1<<endl;
}
void solve2(){
	cin>>s;n=s.size();
	fora(i,1,n+1){
		f[i]=f[i-1]*base+s[i-1];
		g[i]=g[i-1]*base;
	}
	fora(i,2,n+1)
		while(i-res>=res&&f[res]==f[i]-f[i-res]*g[res]){
			pos=i-res;
			res++;
		}
	cout<<res-1<<' '<<pos+1;
}
