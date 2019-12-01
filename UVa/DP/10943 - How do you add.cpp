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
void solve();
void solve2();
int memo[110][110];
int ways(int n,int k){
	if(k==1)
		return 1;
	if(memo[n][k]!=-1)
		return memo[n][k];
	int ans=0;
	fora(i,0,n+1)
		ans+=ways(n-i,k-1)%1000000;
	return memo[n][k]=ans%1000000;
}
int main(){
	io;
//	solve();// top - down
	solve2();// bottom - up
	return 0;
}

void solve(){
	int n,k;
	memset(memo,-1,sizeof memo);
	while(scanf("%d %d\n",&n,&k)&&n&&k){
		printf("%d\n",ways(n,k));
	}
}

void solve2(){
	int n,k;
	while(scanf("%d %d\n",&n,&k)&&n&&k){
		int dp[n+1][k+1]={};
		fora(i,0,n+1){
			dp[i][1]=1;
		}
		fora(i,2,k+1){
			dp[0][i]=1;
			fora(j,1,n+1){
				dp[j][i]=dp[j-1][i]+dp[j][i-1];
				dp[j][i]%=1000000;
			}
		}
		printf("%d\n",dp[n][k]);
	}
}
