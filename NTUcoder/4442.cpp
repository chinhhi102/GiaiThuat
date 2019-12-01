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

int main(){
	io;
	solve();
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	int dp[n+1][m+1]={};
	int a[n+1][m+1]={};
	fora(i,1,n+1)
		fora(j,1,m+1)
			cin>>a[i][j];
	fora(d,1,n+1)
		fora(i,1,m+1){
			dp[d][i]=a[d][i];
			fora(j,0,i+1){
				dp[d][i]=max(dp[d][i],a[d][i-j]+dp[d-1][j]);
//				cout<<"a["<<d<<"]["<<i-j<<"]="<<a[d][i-j]<<' ';
			}//cout<<endl;		
//			cout<<dp[d][i]<<' ';
		}
	cout<<dp[n][m]<<endl;
	int res[n+1]={};
	int s=dp[n][m];
	int sz=n+1;
	while(s){
		if(dp[n][m]!=dp[n-1][m]){
			fora(i,0,m){
				if(s-a[n][m-i]==dp[n-1][i]){
					s-=a[n][m-i];
					res[n]=m-i;
//					cout<<"   ="<<a[n][m-i]<<endl;
					m=i;
					break;
				}
			}
		}
		n--;
	}
	fora(i,1,sz)
		cout<<res[i]<<endl;
}