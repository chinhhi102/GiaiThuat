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
#define mem(a) memset(a,-1,sizeof a)
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
string s;
int memo[2000][2000];
int len(int l, int r){
	if(memo[l][r]!=-1)
		return memo[l][r];
	if(l==r)
		return memo[l][r]=1;
	if(l+1==r)
		return memo[l][r]=(s[l]==s[r]?2:1);
	if(s[l]==s[r])
		return memo[l][r]=2+len(l+1,r-1);
	else
		return memo[l][r]=max(len(l,r-1),len(l+1,r));
}
int main(){
	io;
	solve();
	return 0;
}
void solve(){
	int n;
	cin>>n;
	cin.ignore();
	while(n--){
		mem(memo);
		getline(cin,s);
		if(s.size()==0)
			cout<<0<<endl;
		else
			cout<<len(0,s.size()-1)<<endl;
	}
}
