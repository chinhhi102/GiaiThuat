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
int A[1001],l,n;
int memo[1001][1001];
int cut(int left,int right);

void solve2();

int main(){
	io;
//	solve();
	solve2();
	return 0;
}

int cut(int left,int right){
	if(left+1==right)
		return 0;
	if(memo[left][right]!=-1)
		return memo[left][right];
	int ans=1000000000;
	fora(i,left+1,right){
		ans=min(ans,cut(left,i)+cut(i,right)+(A[right]-A[left]));
	}
	return memo[left][right]=memo[right][left]=ans;
}

void solve(){
	while(scanf("%d",&l)&&l){
		scanf("%d",&n);
		fora(i,1,n+1)
			scanf("%d",&A[i]);
		memset(memo,-1,sizeof memo);
		A[0]=0;
		A[n+1]=l;
		printf("The minimum cutting is %d.\n",cut(0,n+1));
	}
}

void solve2(){
	int l;
	while(scanf("%d",&l)&&l){
		int n;
		scanf("%d",&n);
		int A[n+2]={},dp[n+2][n+2]={};
		fora(i,1,n+1){
			scanf("%d",&A[i]);
		}
		A[++n]=l;
		fora(i,2,n+1){
			for(int a=0,b=a+i;b<=n;a++,b++){
				int minx=1000000000,m;
				int x=A[b]-A[a];
				fora(c,a+1,b){
					m=dp[a][c]+dp[c][b]+x;
					minx=min(minx,m);
				}
				dp[a][b]=minx;
//				printf("%d\n",x);
			}
		}
		printf("The minimum cutting is %d.\n",dp[0][n]);
	}
}
