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
int S[41];
int n,s,p;
int minx=50;
bool cmp(int x,int y){return x>y;}
bool sol=false;
void backtrack(int cur,int presum,int t){
	if(t+1>=minx&&sol)
		return;
	int newsum=presum+S[cur];
	if(newsum==s){
		minx=min(minx,t+1);
		sol=true;
		return;
	}
	if(newsum<s)
		fora(i,cur+1,n)
			if(newsum+S[i]*(n-i+1)>=s&&t+1<minx)
				backtrack(i,newsum,t+1);
}
int main(){
	io;
	solve();
	return 0;
}

void solve(){
	cin>>n>>s>>p;
	fora(i,0,n)
		cin>>S[i];
	sort(S,S+n,cmp);
	backtrack(0,0,0);
	cout<<(minx==50?-1:minx*p);
}
