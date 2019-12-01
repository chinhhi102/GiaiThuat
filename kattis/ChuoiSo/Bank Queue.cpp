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
#include <list>
#include <stack>
#include <iterator>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

bool cmd(pair<int,int> x,pair<int,int> y){
	if(x.ss==y.ss)return x.ff>y.ff;
	else return x.ss<y.ss;
}

int main(){
	io;
	int n,t,ans=0,ti=0;
	c2(n,t);
	vector<pair<int,int> > que;
	while(n--){
		int x,y;
		c2(x,y);
		que.pb(make_pair(x,y));
	}
	sort(que.begin(),que.end(),cmd);
	fora(i,0,que.size()){
		if(que[i].ss-ti>=0){
			ans+=que[i].ff;
			ti++;
		}
		if(ti==t)break;
	}
	cout<<ans;
	return 0;
}
