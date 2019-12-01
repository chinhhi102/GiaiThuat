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
#define M 1000007
void solve();
struct matrix{
	ll fibo[3][3]={};
};
matrix F;
matrix operator * (const matrix x,const matrix y){
	matrix res;
	fora(i,1,3)
		fora(j,1,3)
			fora(k,1,3)
				res.fibo[i][j]+=x.fibo[i][k]*y.fibo[k][j],res.fibo[i][j]%=M;
	return res;
}
matrix mul(ll n){
	if(n>0){
		if(n==1)
			return F;
		matrix t=mul(n/2);
		t=t*t;
		if(n&1)
			t=t*F;
		return t;
	}
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	ll n;
	cin>>n;
	if(n==1||n==2)
		cout<<1;
	else{
		matrix res;
		F.fibo[1][1]=F.fibo[2][1]=F.fibo[1][2]=1;
		res=mul(n-2);
		cout<<(res.fibo[1][1]+res.fibo[1][2])%M;
	}
}
