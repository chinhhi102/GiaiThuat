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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	fora(i,0,n)
		cin>>v[i];
	vector<int> l(n,0);
	vector<int> r(n,0);
	int maxxl=0,maxxr=n-1;
	l[0]=0;
	r[n-1]=0;
	fora(i,1,n){
		l[i]=i-maxxl;
		int maxx=maxxl;
		
		if(v[i]>v[i-1])
			maxxl=i;
		fors(j,maxx,0)
			if(v[maxx]<=v[j]){
				l[i]++;
				maxx=j;
//		if(i==7)
//			cout<<l[i]<<"->";
			}
	}
	fors(i,n-1,0){
		r[i]=maxxr-i;
		int maxx=maxxr;
		if(v[i]>v[i+1])
			maxxr=i;
		fora(j,maxx+1,n)
			if(v[maxx]<=v[j]){
				r[i]++;
				maxx=j;
			}
	}
	string s;
	cin>>s;
	fora(i,0,s.size()){
		cout<<(s[i]=='E'?r[i]:l[i])<<' ';
	}
}
/*
11
4 1 5 1 6 1 4 1 5 1 4
WWWWWWWWWWW
*/
