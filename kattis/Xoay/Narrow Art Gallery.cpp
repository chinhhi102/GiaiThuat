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
#define M_PI 3.14159265358979323846
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

const int INF = 9999999;

int n,k;
int r[300][3];
int m[300][500][3];

int d(int a, int u, int w) {
	return m[a][u][w]=m[a][u][w]!=-1?m[a][u][w]:a>=n?u==k?0:INF:min(d(a+1,u+1,w)+r[a][w],min(d(a+2,u+1,1-w)+r[a][w],min(d(a+1,u,1-w),d(a+1,u,w))));
}

int main(){
	while(cin >> n >> k) {
		if(n+k == 0) break;
		memset(r,0,sizeof(r));
		memset(m,-1,sizeof(m));
		fora(i,0,n) cin >> r[i][0] >> r[i][1];
		int t = 0;
		fora(i,0,n) t+=r[i][0]+r[i][1];
		int m = min(d(0,0,0), d(0,0,1));
		cout << t-m << endl;
	}
	return 0;
}
