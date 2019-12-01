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
ll n,res=0;
map<string,ll> m;
int times[3]={};
int tt[3]={};
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n;
	string s1,s2;
	char c1,c2;
	fora(i,0,n){
		cin>>s1>>s2;
		memset(tt,0,sizeof tt);
		memset(times,0,sizeof times);
		fora(i,0,3){
			cin>>c1>>c2;
			tt[i]=int((c1-'0')*10+(c2-'0'));
		}
		fora(i,0,3){
			cin>>c1>>c2;
			times[i]=int((c1-'0')*10+(c2-'0'));
		}
		if(times[2]>=tt[2])
			times[2]-=tt[2];
		else{
			times[2]=times[2]-tt[2]+60;
			tt[1]++;
		}
		if(times[1]>=tt[1])
			times[1]-=tt[1];
		else{
			times[1]=times[1]-tt[1]+60;
			tt[0]++;
		}
		times[0]-=tt[0];
		if(times[0]<0)times[0]+=24;
		m[s1]+=(times[0]*3600+times[1]*60+times[2])*2;
		res=max(res,m[s1]);
		m[s2]+=(times[0]*3600+times[1]*60+times[2]);
		res=max(res,m[s2]);
	}
	cout<<res;
}
